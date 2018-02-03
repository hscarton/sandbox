#pragma once
#ifndef HIGH_CONTRAST_EFFECT_H
#define HIGH_CONTRAST_EFFECT_H

#include "ImageEffect.h"

//this image effect will add high contrast to a picture
class HighContrastImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);
                                
                                //If a red, green, or blue pixel is greater than
                                //255/2, then max out to 255. Else, set the red,
                                //green, and blue pixel to 0.
                                
				if (p.getRed() > (255/2))
				{
					p.setRed(255);
				}

				else if (p.getGreen() > (255/2))
				{
					p.setGreen(255);
				}

				else if (p.getBlue() > (255/2))
				{
					p.setBlue(255);
				}
                                
                else
                {
                    p.setRed(0);
                    p.setGreen(0);
                    p.setBlue(0);
                }

				
			}
		}
	}

};

#endif // !HIGH_CONTRAST_EFFECT_H
