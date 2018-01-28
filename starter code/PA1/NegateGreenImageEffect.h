#pragma once
#ifndef NEGATE_GREEN_EFFECT_H
#define NEGATE_GREEN_EFFECT_H

#include "ImageEffect.h"

//this image effect will negate all green pixels in a picture
class NegateGreenImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				//subtract the current green pixel number from 255
				//to get the negate green number
				int g_num = 255 - p.getGreen();
				p.setGreen(g_num);
			}
		}
    }

};

#endif // !NEGATE_GREEN_EFFECT_H
