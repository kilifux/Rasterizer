#include "Rasterizer.h"
#include "Vector.h"
#include "TGABuffer.h"
#include <algorithm>
#include "Triangle.h"
#include <iostream>
#include "Light.h"
#include "VertexProcessor.h"
#include "Cylinder.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

Rasterizer::Rasterizer(TGABuffer *buffer) {
    tgaBuffer = buffer;
}

void Rasterizer::Rasterize(Mesh &mesh, Matrix4 &model, bool lightPixel) {

    for (auto &triangle : mesh.triangles)
    {
        RenderTriangle(triangle, model, lightPixel);
    }
}

void Rasterizer::RenderTriangle(Triangle &triangle, Matrix4 &model, bool lightPixel) {

    int width = tgaBuffer->GetWidth();
    int height = tgaBuffer->GetHeight();

    Matrix4 viewMatrix = VertexProcessor::setLookAt({0, 1, 2}, {0, 2, 0}, {0, 1, 0});

    Matrix4 projectionMatrix = VertexProcessor::setPerspective(120.f, 1.f, 0.01f, 100.f);

    Matrix4 camera =  Matrix4::Identity();

    camera = camera * projectionMatrix * viewMatrix;

    Vector4 transformedVertex1 =  model * camera * Vector4(triangle.vertices[0].position.x, triangle.vertices[0].position.y, triangle.vertices[0].position.z, 1.0f);
    int x1 = (transformedVertex1.x + 1.0f) * width * 0.5f;
    int y1 = (transformedVertex1.y + 1.0f) * height * 0.5f;

    Vector4 transformedVertex2 = model * camera * Vector4(triangle.vertices[1].position.x, triangle.vertices[1].position.y, triangle.vertices[1].position.z, 1.0f);
    int x2 = (transformedVertex2.x + 1.0f) * width * 0.5f;
    int y2 = (transformedVertex2.y + 1.0f) * height * 0.5f;

    Vector4 transformedVertex3 = model * camera * Vector4(triangle.vertices[2].position.x, triangle.vertices[2].position.y, triangle.vertices[2].position.z, 1.0f);
    int x3 = (transformedVertex3.x + 1.0f) * width * 0.5f;
    int y3 = (transformedVertex3.y + 1.0f) * height * 0.5f;

    int z1 = triangle.vertices[0].position.z, z2 = triangle.vertices[1].position.z, z3 = triangle.vertices[2].position.z;

    int minx = std::min({x1, x2, x3});
    int maxx = std::max({x1, x2, x3});
    int miny = std::min({y1, y2, y3});
    int maxy = std::max({y1, y2, y3});

    minx = std::max(minx, 0);
    maxx = std::min(maxx, width - 1);
    miny = std::max(miny, 0);
    maxy = std::min(maxy, height - 1);

    float dx12 = x1 - x2;
    float dx13 = x1 - x3;
    float dx23 = x2 - x3;
    float dx31 = x3 - x1;
    float dx32 = x3 - x2;
    float dy12 = y1 - y2;
    float dy13 = y1 - y3;
    float dy23 = y2 - y3;
    float dy31 = y3 - y1;

    bool tl1 = (dy12 < 0 || (dy12 == 0 && dx12 > 0));
    bool tl2 = (dy23 < 0 || (dy23 == 0 && dx23 > 0));
    bool tl3 = (dy31 < 0 || (dy31 == 0 && dx31 > 0));

    for (int x = minx; x < maxx; ++x) {
        for (int y = miny; y < maxy; ++y) {

            float edge1 = (dx12) * (y - y1) - (dy12) * (x - x1);
            float edge2 = (dx23) * (y - y2) - (dy23) * (x - x2);
            float edge3 =  (dx31) * (y - y3) - (dy31) * (x - x3);

            if (   (edge1 > 0 || (edge1 >= 0 && tl1))
                   && (edge2 > 0 || (edge2 >= 0 && tl2))
                   && (edge3 > 0 || (edge3 >= 0 && tl3))) {

                float bar1 = ((dy23) * (x - x3) + (dx32) * (y - y3)) / ((dy23) * (dx13) + (dx32) * (dy13));
                float bar2 = ((dy31) * (x - x3) + (dx13) * (y - y3)) / ((dy31) * (dx23) + (dx13) * (dy23));
                float bar3 = 1.f - bar1 - bar2;


                Vector interpolatedNormal = (triangle.vertices[0].normal * bar1 + triangle.vertices[1].normal * bar2 + triangle.vertices[2].normal * bar3).Normalize();
                Vector interpolatedPosition = Vector(triangle.vertices[0].position.x * bar1 + triangle.vertices[1].position.x * bar2 + triangle.vertices[2].position.x * bar3,
                                                     triangle.vertices[0].position.y * bar1 + triangle.vertices[1].position.y * bar2 + triangle.vertices[2].position.y * bar3,
                                                     triangle.vertices[0].position.z * bar1 + triangle.vertices[1].position.z * bar2 + triangle.vertices[2].position.z * bar3);

                Vector cameraPosition{0, 0, 0};

                if (lightPixel)
                {
                    Vector lightingColor = CalculatePixelLighting(interpolatedNormal, interpolatedPosition, cameraPosition);

                    float depth = bar1 * z1 + bar2 * z2 + bar3 * z3;
                    if (depth < tgaBuffer->GetDepth()[y * width + x])
                    {
                        tgaBuffer->GetColorBuffer()[y * width + x] = Vector::ToColor(lightingColor);
                        tgaBuffer->GetDepth()[y * width + x] = depth;
                    }
                }
                else {

                for (auto& vertex : triangle.vertices)
                {
                    CalculateLighting(vertex);
                }

                Vector color1 = Vector::ToVector(triangle.vertices[0].color);
                Vector color2 = Vector::ToVector(triangle.vertices[1].color);
                Vector color3 = Vector::ToVector(triangle.vertices[2].color);
                Vector color =  color1 * bar1 + color2 * bar2 + color3 * bar3;
                float depth = bar1 * z1 + bar2 * z2 + bar3 * z3;

                if (depth < tgaBuffer->GetDepth()[y * width + x])
                {
                    tgaBuffer->GetColorBuffer()[y * width + x] = Vector::ToColor(color);
                    tgaBuffer->GetDepth()[y * width + x] = depth;
                }

                }
            }
        }
    }
}


Vector Rasterizer::CalculatePixelLighting(Vector& normal, const Vector& position, const Vector& cameraPosition) {
    Vector lightingColor(0.0f, 0.0f, 0.0f);

    for (auto& light : sceneLights) {
        Vector lightDirection;
        float attenuationFactor = 1.0f; // Faktor tłumienia, może być dostosowany do odległości od światła

        if (dynamic_cast<DirectionalLight*>(light) != nullptr) {
            lightDirection = -dynamic_cast<DirectionalLight*>(light)->direction; // Kierunek światła jest przeciwny do kierunku światła kierunkowego
        } else if (dynamic_cast<PointLight*>(light) != nullptr) {
            lightDirection = (dynamic_cast<PointLight*>(light)->position - position).Normalize(); // Kierunek do punktowego światła
            // Tutaj możesz dodać obliczanie tłumienia na podstawie odległości od światła punktowego
        } else if (auto spotLight = dynamic_cast<SpotLight*>(light)) {
            lightDirection = (spotLight->position - position).Normalize(); // Kierunek do reflektora
            float angle = std::acos(normal.dotProduct(lightDirection));
            float cutoffRadians = spotLight->cutoff * (M_PI / 180.0f); // Konwersja kąta odcięcia na radiany
            if (angle > cutoffRadians) {
                attenuationFactor = 0.0f; // Światło reflektorowe nie oświetla tego piksela, jeśli znajduje się poza kątem odcięcia
            }
        }

        // Oblicz składowe oświetlenia
        Vector ambientComponent = light->ambient;
        float diffuseIntensity = std::max(0.0f,  normal.dotProduct(lightDirection));
        Vector diffuseComponent = light->diffuse * diffuseIntensity;

        Vector viewDirection = (cameraPosition - position).Normalize();
        Vector halfwayDirection = (lightDirection + viewDirection).Normalize();
        float specularIntensity = std::pow(std::max(0.0f, normal.dotProduct(halfwayDirection)), light->shininess);
        Vector specularComponent = light->specular * specularIntensity;

        // Dodaj składowe oświetlenia do koloru oświetlenia punktu
        lightingColor = lightingColor + ambientComponent + (diffuseComponent + specularComponent) * attenuationFactor;
    }

    // Ogranicz wartości koloru do zakresu [0, 1]
    lightingColor.x = std::min(1.0f, std::max(0.0f, lightingColor.x));
    lightingColor.y = std::min(1.0f, std::max(0.0f, lightingColor.y));
    lightingColor.z = std::min(1.0f, std::max(0.0f, lightingColor.z));

    return lightingColor;
}



void Rasterizer::CalculateLighting(Vertex &vertex) {
    Vector lightingColor(0.0f, 0.0f, 0.0f);
    Vector cameraPosition{0, 0, 0};

    // Iterujemy przez wszystkie światła na scenie
    for (auto& light : sceneLights) {
        // Obliczamy wektor normalny w lokalnym układzie współrzędnych
        Vector localNormal = vertex.normal;

        // Obliczamy wektor do światła
        Vector lightDirection;

        if (dynamic_cast<PointLight*>(light) != nullptr) {
            // Jeśli światło punktowe, obliczamy wektor do światła
            lightDirection = (dynamic_cast<PointLight*>(light)->position - vertex.position).Normalize();
        } else if (dynamic_cast<DirectionalLight*>(light) != nullptr) {
            // Jeśli światło kierunkowe, używamy jego kierunku jako wektora do światła
            lightDirection = -dynamic_cast<DirectionalLight*>(light)->direction;
        } else if (auto spotLight = dynamic_cast<SpotLight*>(light)) {
            // Jeśli światło reflektorowe, obliczamy wektor do reflektora
            lightDirection = (spotLight->position - vertex.position).Normalize();
            float angle = std::acos(localNormal.dotProduct(lightDirection));
            float cutoffRadians = spotLight->cutoff * (M_PI / 180.0f); // Konwersja kąta odcięcia na radiany
            if (angle > cutoffRadians) {
                continue; // Światło reflektorowe nie oświetla tego wierzchołka, jeśli znajduje się poza kątem odcięcia
            }
        }

        // Obliczamy składowe oświetlenia
        Vector ambientComponent = light->ambient;
        Vector diffuseComponent = light->diffuse * std::max(0.0f, localNormal.dotProduct(lightDirection));
        Vector specularComponent(0.0f, 0.0f, 0.0f);

        if (localNormal.dotProduct(lightDirection) > 0) {
            // Obliczamy składową odbicia światła tylko jeśli światło jest padające na powierzchnię
            Vector viewDirection = (cameraPosition - vertex.position).Normalize();
            Vector halfwayDirection = (lightDirection + viewDirection).Normalize();
            float specularFactor = std::pow(std::max(0.0f, localNormal.dotProduct(halfwayDirection)), light->shininess);
            specularComponent = light->specular * specularFactor;
        }

        // Dodajemy składowe oświetlenia od tego światła do ogólnego koloru oświetlenia wierzchołka
        lightingColor = lightingColor + ambientComponent + diffuseComponent + specularComponent;
    }

    // Ograniczenie wartości koloru do zakresu [0, 1]
    lightingColor.x = std::min(1.0f, std::max(0.0f, lightingColor.x));
    lightingColor.y = std::min(1.0f, std::max(0.0f, lightingColor.y));
    lightingColor.z = std::min(1.0f, std::max(0.0f, lightingColor.z));

    // Aktualizacja koloru wierzchołka
    vertex.color = Vector::ToColor(lightingColor);
}





