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


#include "camera.h"

Camera::Camera(int screenHeight,int screenWidth)
{
   this->screenHeight = screenHeight;
   this->screenWidth = screenWidth;
   convert = new  ConvertUtililty(screenHeight,screenWidth);
}
void Camera::setCameraPosition(b2Vec2 characterPOS,float angle)
{      GM_POINT* point = convert->convertB2Vec2ToGM_Point(characterPOS);
       //x_position = (point->x + character_width/2) - screenWidth/2;
       //y_position = (point->y+ character_height/2) - screenHeight/2;
       
       
       /************************************************************************/
       /*THE NEW CAMERA CODE FOR THE GAME SYSTEM MAKES MORE SENSE THAN THE REST*/
       /************************************************************************/
      float cameraPosX = ( x_position < 0 ) ? 0 : x_position;
      float cameraPosY = ( y_position < 0 ) ? 0 : y_position;
       glMatrixMode(GL_PROJECTION);
       
       glLoadIdentity();
       //glOrtho(cameraPosX,cameraPosX + screenWidth,
	      //cameraPosY + screenHeight,cameraPosY,-1,1);
         glOrtho(point->x -screenWidth/2.0,point->x + screenWidth/2.0,
	         point->y -screenHeight/2.0,point->y + screenHeight/2.0,-1,1);
        
        //glTranslatef(-point->x,-point->y,0.0f);
	glRotatef(convert->convertRadiansToDegrees(angle),0.0f,0.0f,1.0f);
	printf("BODY POSITION x:[%4.2f].y:[%4.2f] angle:[%4.2f]\n",-point->x,-point->y,convert->convertRadiansToDegrees(angle));
       
        glMatrixMode(GL_MODELVIEW);
       
       
}

void Camera::zoomCameraOnPlayer(float zoomFactor)
{
 // gluPerspective(fieldOfView * zoomFactor, screenWidth/screenHeight, 1);
}

void Camera::rotationResolver(float x_position, float y_position)
{
   x_angle += x_position - x_previous_position;
   y_angle += y_position - y_previous_position;
  
   x_previous_position = x_position;
   y_previous_position = y_position;
}

void Camera::setCharacterSize(float character_width, float character_height)
{
   this->character_width = character_width;
   this->character_height = character_height;
}

Camera::~Camera()
{

}

