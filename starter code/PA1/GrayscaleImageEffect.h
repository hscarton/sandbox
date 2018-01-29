#pragma once
#ifndef GRAYSCALE_EFFECT_H
#define GRAYSCALE_EFFECT_H

#include "ImageEffect.h"

//this image effect will make the image black and white
class GrayscaleImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);
				
				int average = (p.getRed() + p.getGreen() + p.getBlue()) / 3;

				p.setRed(average);
				p.setGreen(average);
				p.setBlue(average);
			}
		}
	}

};

#endif // !GRAYSCALE_EFFECT_H