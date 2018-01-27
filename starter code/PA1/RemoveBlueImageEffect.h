#pragma once
#ifndef REMOVE_BLUE_EFFECT_H
#define REMOVE_BLUE_EFFECT_H

#include "ImageEffect.h"

//this image effect will remove all blue from a picture
class RemoveBlueImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
		Pixel& p = doc.getPixel(i, j);
		p.setBlue(0);
    }

};

#endif // !REMOVE_BLUE_EFFECT_H
