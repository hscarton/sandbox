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
                            
                            //If the red pixel after adding the random number
                            //to it is below 0 or above 255, we will bring it
                            //into range. Otherwise, we will set the red pixel
                            //as is, to RedPix.
                            
                            if(RedPix < 0)
                            {
                                p.setRed(0);
                            }

                            else if(RedPix > 255)
                            {
                                p.setRed(255);
                            }
                            
                            else
                            {
                                p.setRed(RedPix);
                            }

                            //If the green pixel after adding the random number
                            //to it is below 0 or above 255, we will bring it
                            //into range. Otherwise, we will set the green pixel
                            //as is, to GreenPix.
                            
                            if(GreenPix < 0)
                            {
                                p.setGreen(0);
                            }

                            else if(GreenPix > 255)
                            {
                                p.setGreen(255);
                            }
                            
                            else
                            {
                                p.setGreen(GreenPix);
                            }

                            //If the blue pixel after adding the random number
                            //to it is below 0 or above 255, we will bring it
                            //into range. Otherwise, we will set the blue pixel
                            //as is, to BluePix.
                            
                            if (BluePix < 0)
                            {
                                p.setBlue(0);
                            }

                            else if (BluePix > 255)
                            {
                                p.setBlue(255);
                            }
                            else 
                            {
                                p.setBlue(BluePix); 
                            }
				
			}
		}
	}

};

#endif // !ADD_NOISE_EFFECT_H
