/*
Scene.cpp
Author: Jason Nguyen
May 3, 2021
*/

#include "Scene.hpp"
#include <iostream>
using namespace std;

Scene::Scene(const std::string& filepath)
{
    std::vector<double> params;
    std::ifstream f{filepath};
    std::string line;
    while (std::getline(f, line))
    {
        istringstream ss{line};
        std::string param;
        ss >> param;
        if (param == "camera")
        {
            for (int i = 0; i < 9; i++)
            {
                if (i == 0)
                {         
                    ss.ignore();
                    ss.ignore();
                }
                else if (i == 1)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 2)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 3)
                {
                    ss >> param;
                    param = param.substr(0, param.size()-1);
                    params.push_back(std::stod(param));
                    ss.ignore();
                    ss.ignore();
                }
                else if (i == 4)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 5)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 6)
                {
                    ss >> param;
                    param = param.substr(0, param.size()-1);
                    params.push_back(std::stod(param));
                }
                else if (i == 7)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 8)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
            }
            camera = Camera(Point(params[0], params[1], params[2]), Point(params[3],params[4],params[5]), params[6], params[7]);
            params.clear();
        }
        else if (param == "sphere")
        {
            for (int i = 0; i < 5; i++)
            {
                if (i == 0)
                {         
                    ss.ignore();
                    ss.ignore();
                }  
                else if (i == 1)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 2)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 3)
                {
                    ss >> param;
                    param = param.substr(0, param.size()-1);
                    params.push_back(std::stod(param));
                }
                else if (i == 4)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
            }
            unique_ptr<Sphere> s = make_unique<Sphere>(Point(params[0],params[1],params[2]), params[3]);
            primitives.emplace_back(s);
            params.clear();
        }
        else if (param == "plane")
        {
            for (int i = 0; i < 7; i++)
            {
                if (i == 0)
                {         
                    ss.ignore();
                    ss.ignore();
                }  
                else if (i == 1)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 2)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 3)
                {
                    ss >> param;
                    param = param.substr(0, param.size()-1);
                    params.push_back(std::stod(param));
                    ss.ignore();
                    ss.ignore();
                }
                else if (i == 4)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 5)
                {
                    ss >> param;
                    params.push_back(std::stod(param));
                }
                else if (i == 6)
                {
                    ss >> param;
                    param = param.substr(0, param.size()-1);
                    params.push_back(std::stod(param));
                }
            }
            unique_ptr<Plane> p = make_unique<Plane>(Point(params[0],params[1],params[2]), Vector(params[3],params[4],params[5]));
            primitives.emplace_back(p);
        }
    }

}

std::optional<Intersection> Scene::find_intersection(Ray r)
{
    Intersection ye;
    ye.distance = INT64_MAX;
    for (int i = 0; i < primitives.size(); i++)
    {
        if (primitives[i]->intersections(r).distance < ye.distance)
        {
            ye = primitives[i]->intersections(r);
        }
    }

    if (ye.distance == 0)
    {
        return {};
    }

    return ye;
}