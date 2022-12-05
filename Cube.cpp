//
// Created by alexc on 11/13/2022.
//

#include "Cube.h"
#include <vector>

std::vector<float> cube_vertices{
        //x,y,z,tx,ty
        //front face
        -.5,-.5, .5,0,0,
        -.5, .5, .5,0,1,
        .5, .5, .5,1,1,
        .5,-.5, .5,1,0,

        //back face
        -.5,-.5, -.5,0,0,
        -.5, .5, -.5,0,1,
        .5,  .5, -.5,1,1,
        .5,-.5, -.5,1,0,

        //top face
        -.5, .5, .5,0,0,
        -.5, .5,-.5,0,1,
        .5, .5,-.5,1,1,
        .5, .5, .5,1,0,

        //bottom face
        -.5,-.5, .5,0,0,
        -.5,-.5,-.5,0,1,
        .5,-.5,-.5,1,1,
        .5,-.5, .5,1,0,

        //left face
        -.5,-.5,-.5,0,0,
        -.5, .5,-.5,0,1,
        -.5, .5, .5,1,1,
        -.5,-.5, .5,1,0,



        //right face
        .5,-.5,-.5,0,0,
        .5, .5,-.5,0,1,
        .5, .5, .5,1,1,
        .5,-.5, .5,1,0
};

std::vector<unsigned int> cube_triangles{
        //Front face
        0,1,2,
        2,3,0,
        //Back face
        4,5,6,
        6,7,4,
        //Top face
        8,9,10,
        10,11,8,
        //Bottom face
        12,13,14,
        14,15,12,
        //Left face
        16,17,18,
        18,19,16,
        //Right face
        20,21,22,
        22,23,20
};

std::optional<VertexArray> Cube::vertexArr;

//If vertexArray has not been initialized, intialize it
//Then returns the value of vertexArray
VertexArray Cube::getCubeVertexArr(){
    if(vertexArr == std::nullopt){
        vertexArr = VertexArray(cube_vertices, 5, cube_triangles);
        //Vertex attributes: 3 floats for rgb color, 2 floats for texture pos
        vertexArr->vertexAttrib(0,3)->vertexAttrib(1,2);
    }
    return *vertexArr;
}



//Creates a new cube object
//Initializes cubeEBO if it has not been initialized.
Cube::Cube( const char* name, int id, Texture texture, glm::vec3 position) : Block(name, id, getCubeVertexArr(), texture, position){};

std::unique_ptr<Block> Cube::clone(glm::vec3 position){
    return std::make_unique<Cube>(Cube(getName(), getId(), getTexture(), position));
}

void Cube::initCubes(){
    blockTypes.push_back(nullptr);
    Texture stone("../textures/stone.png",{});
    blockTypes.push_back(std::make_unique<Cube>(Cube("Stone",1,stone,glm::vec3(0,0,0))));
    Texture sandstone("../textures/sandstone.png", {});
    blockTypes.push_back(std::make_unique<Cube>(Cube("Sandstone", 2, sandstone, glm::vec3(0,0,0))));
    Texture granite("../textures/granite.png",{});
    blockTypes.push_back(std::make_unique<Cube>(Cube("Granite", 3, granite, glm::vec3(0,0,0))));
    Texture calcite("../textures/calcite.png", {});
    blockTypes.push_back(std::make_unique<Cube>(Cube("Calcite", 4, calcite, glm::vec3(0,0,0))));

}