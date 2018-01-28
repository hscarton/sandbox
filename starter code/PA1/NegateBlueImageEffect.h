#pragma once
#ifndef NEGATE_BLUE_EFFECT_H
#define NEGATE_BLUE_EFFECT_H

#include "ImageEffect.h"

//this image effect will negate all blue pixels in a picture
class NegateBlueImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				//subtract the current blue pixel number from 255
				//to get the negate blue number
				int b_num = 255 - p.getBlue();
				p.setBlue(b_num);
			}
		}
    }

};

#endif // !NEGATE_BLUE_EFFECT_H
