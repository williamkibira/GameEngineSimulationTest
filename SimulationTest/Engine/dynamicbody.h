/*
    Copyright (c) 2013, <copyright holder> <email>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <Box2D/Box2D.h>
#include <TmxParser/Tmx.h>
#include <stdio.h>
#include <SDL2/SDL_opengl.h>
#include "body.h"
#include "../Settings/constants.h"
#include "../Tools/convertutililty.h"

#ifndef DYNAMICBODY_H
#define DYNAMICBODY_H

class DynamicBody: public Body
{
  
public:
  DynamicBody(b2World* world, float positionX,float positionY,const Tmx::Polygon* polygon,ConvertUtililty* convert);
  
  void engageBody();
  void setBodyPosition(float positionX,float positionY);
  b2Vec2 getBodyPosition();
  void drawPoint(float pos_x,float pos_y);
  void CCWT();
  void Update();
  void setDensity(float density);
  void setFriction(float friction);
  void getUserData(void* userdata);
  DynamicBody *returnBody();
  virtual ~DynamicBody();
  
private:
  int NumberOfPolygonVertices;
  int k;
  int area;
  b2PolygonShape reverseShape;
  ConvertUtililty* convert;
};
#endif // DYNAMICBODY_H
