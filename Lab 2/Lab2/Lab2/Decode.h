#pragma once
#ifndef DECODE_H
#define DECODE_H

#include <vector>
#include "ImageEffect.h"

//this image effect will make the image black and white
class Decode : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		//to hold the chars gotten from red pixel
		vector<char> secretWord{};
		//to hold the x coordinate of the next char
		int g = p.getGreen();
		//to hold the y coordinate of the next char
		int b = p.getBlue();

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				//to get the base case pixel
				if ((i == 0) && (j == 0))
				{
					secretWord.push_back(p.getRed());
					g = p.getGreen();
					b = p.getBlue();
				}
				//to add the next code char to the secretWord vector
				if ((i == g) && (j == b))
				{
					secretWord.push_back(p.getRed());
					g = p.getGreen();
					b = p.getBlue();
				}
			}
		}
		//return the vector secretWord
	}

};

#endif // !DECODE_H