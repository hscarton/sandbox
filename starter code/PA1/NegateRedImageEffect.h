#pragma once
#ifndef NEGATE_RED_EFFECT_H
#define NEGATE_RED_EFFECT_H

#include "ImageEffect.h"

//this image effect will negate all red pixels in a picture
class NegateRedImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				//subtract the current red pixel number from 255
				//to get the negate red number
				int r_num = 255 - p.getRed();
				p.setRed(r_num);
			}
		}
    }

};

#endif // !NEGATE_RED_EFFECT_H
