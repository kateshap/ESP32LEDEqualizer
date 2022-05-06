#ifndef MATRIX_TEST_EFFECT_H_
#define MATRIX_TEST_EFFECT_H_

#include "LedEffectBase.hpp"


class MatrixTestEffect : public LedEffectBase {

public:
    MatrixTestEffect(MatrixDimenType width, MatrixDimenType height) : LedEffectBase(width, height) {
        x = 0;
        y = 0;
        xCnt = 0;
        yCnt = 0;
    }
    virtual ~MatrixTestEffect() override {}

    /*virtual void applyFrame(LedMatrix* ledMatrix) override {
        for (x = 0; x < getWidth(); ++x) {
            for (y = 0; y < getHeight(); ++y) {
                if (x == xCnt && y == yCnt) {
                    ledMatrix->setPixelColor(x, y, 0, 0, 1);
                } else {
                    ledMatrix->setPixelColor(x, y, 0, 0, 0);
                }
            }
        }

        ++xCnt;
        if (xCnt == 16)
        {
            xCnt = 0;
            ++yCnt;
        }
        if (yCnt == 16)
        {
            xCnt = 0;
            yCnt = 0;
        }
    }*/

    virtual void applyFrame(LedMatrix* ledMatrix) override {
        xCnt = 0;
        yCnt = 0;
        for (x = 0; x < getWidth(); ++x) {
            for (y = 0; y < getHeight(); ++y) {
                if (x == xCnt && y == yCnt) {
                    ledMatrix->setPixelColor(x, y, 1, 0, 1);
                } 
                else if ((x == 8 && y ==8) || (x == 7 && y ==7) || (x == 8 && y ==7) || (x == 7 && y ==8)
                 || (x == 5 && y ==6) || (x == 5 && y ==7) || (x == 5 && y ==8) || (x == 5 && y ==9) 
                || (x == 10 && y ==6) || (x == 10 && y ==7) || (x == 10 && y ==8) || (x == 10 && y ==9)
                || (x == 6 && y ==5) || (x == 7 && y ==5) || (x == 8 && y ==5) || (x == 9 && y ==5) 
                || (x == 6 && y ==10) || (x == 7 && y ==10) || (x == 8 && y ==10) || (x == 9 && y ==10) ) {                                  
                    ledMatrix->setPixelColor(x, y, 1, 1, 0);
                } 
                else {
                    ledMatrix->setPixelColor(x, y, 0, 0, 0);
                }
                ++yCnt; 
                 if (yCnt == 16)
            {
                    xCnt = 0;
                    yCnt = 0;
            }
                
            }
             
             ++xCnt;
             if (xCnt == 16)
                {
                    xCnt = 0;
                    yCnt = 0;
                }
               
        }
    }


private:
    MatrixDimenType x = 0;
    MatrixDimenType y = 0;
    MatrixDimenType xCnt = 0;
    MatrixDimenType yCnt = 0;        

};

#endif /* MATRIX_TEST_EFFECT_H_ */