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
#include "body.h"
#include <TmxParser/Tmx.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "../Tools/convertutililty.h"
#include "../Settings/constants.h"

#ifndef GROUNDBODY_H
#define GROUNDBODY_H

class GroundBody:public Body
{
  
public:
  GroundBody(b2World* world, float positionX,float positionY,const Tmx::Polyline* polyline,ConvertUtililty* convert);
  void engageGround();
  void setBodyPosition(float positionX,float positionY);
  b2Vec2 getBodyPosition();
  void drawPoint(float pos_x,float pos_y);
  void getUserData(void* userdata);
  void setDensity(float density);
  void setFriction(float friction);
  void Update();
  GroundBody* returnBody();
  virtual ~GroundBody();
private:
  b2ChainShape chain;
  ConvertUtililty* convert;
};


#endif // GROUNDBODY_H
