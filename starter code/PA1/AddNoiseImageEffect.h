#pragma once
#ifndef ADD_NOISE_EFFECT_H
#define ADD_NOISE_EFFECT_H

#include "ImageEffect.h"
#include "RandNum.h"

//this image effect will add noise to a picture
class AddNoiseImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				RandNum num;
				int RedPix = p.getRed() + num.returnRandNum();
				int GreenPix = p.getGreen() + num.returnRandNum();
				int BluePix = p.getBlue() + num.returnRandNum();

				if(RedPix < 0)
				{
					p.setRed(0);
				}

				if(RedPix > 255)
				{
					p.setRed(255);
				}

				if(GreenPix < 0)
				{
					p.setGreen(0);
				}

				if(GreenPix > 255)
				{
					p.setGreen(255);
				}

				if (BluePix < 0)
				{
					p.setBlue(0);
				}

				if (BluePix > 255)
				{
					p.setBlue(255);
				}

				p.setRed(RedPix);
				p.setGreen(GreenPix);
				p.setBlue(BluePix);
			}
		}
	}

};

#endif // !ADD_NOISE_EFFECT_H
