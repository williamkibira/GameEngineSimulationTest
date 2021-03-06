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


#include "touchscreeninput.h"

TouchScreenInput::TouchScreenInput(SDL_Event* event)
{
  this->event = event;
}
int TouchScreenInput::getNumberOfFingers()
{
  if(event->type == SDL_FINGERDOWN)
  {
   
    
    return SDL_GetNumTouchFingers(state->touchId);
  }
}
GM_POINT* TouchScreenInput::getPosition()
{
  if(event->type == SDL_FINGERDOWN)
  {
    finger = SDL_GetTouchFinger(event->tfinger.touchId,0);
    
   temp_point->x =  state->x;
   temp_point->y =  state->y;
  }
  return temp_point;
}
GM_POINT* TouchScreenInput::getPositionDelta()
{
  if(event->type == SDL_FINGERDOWN)
  {
    finger = SDL_GetTouchFinger(event->tfinger.touchId,0);
    
    delta->x =  state->dx;
    delta->y =  state->dy;
  }
  return delta;
}

TouchScreenInput::~TouchScreenInput()
{

}

