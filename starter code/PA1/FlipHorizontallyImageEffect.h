#pragma once
#ifndef FLIP_HORIZONTALLY_EFFECT_H
#define FLIP_HORIZONTALLY_EFFECT_H

#include "ImageEffect.h"

//this image effect will remove all green from a picture
class FlipHorizontallyImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		int WidthMax = doc.getWidth();
		int HeightMax = doc.getHeight();

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int x = HeightMax - i + 1;
				int y = WidthMax - j + 1;

				Pixel& p = doc.getPixel(x, y);
			}
		}
	}

};

#endif // !FLIP_HORIZONTALLY_EFFECT_H
