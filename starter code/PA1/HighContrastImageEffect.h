#pragma once
#ifndef HIGH_CONTRAST_EFFECT_H
#define HIGH_CONTRAST_EFFECT_H

#include "ImageEffect.h"

//this image effect will add noise to a picture
class HighContrastImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				if (p.getRed() > (255/2))
				{
					p.setRed(255);
				}

				if (p.getGreen() > (255/2))
				{
					p.setGreen(255);
				}

				if (p.getBlue() > (255/2))
				{
					p.setBlue(255);
				}

				p.setRed(0);
				p.setGreen(0);
				p.setBlue(0);
			}
		}
	}

};

#endif // !HIGH_CONTRAST_EFFECT_H
