#pragma once
#ifndef REMOVE_GREEN_EFFECT_H
#define REMOVE_GREEN_EFFECT_H

#include "ImageEffect.h"

//this image effect will remove all green from a picture
class RemoveGreenImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
		Pixel& p = doc.getPixel(i, j);
		p.setGreen(0);
    }

};

#endif // !REMOVE_GREEN_EFFECT_H



