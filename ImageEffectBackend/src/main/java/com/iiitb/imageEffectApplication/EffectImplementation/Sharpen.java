package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.SharpenInterface;
import libraryInterfaces.Pixel;

public class Sharpen implements SingleValueParameterizableEffect{
    private float parameterValue;

    @Override
    public void setParameterValue(float parameterValue) throws IllegalParameterException {
        if(parameterValue>=0 && parameterValue<=100){
            this.parameterValue = parameterValue;
        }
        else throw new IllegalParameterException("Sharpness takes only values between 0 to 100");
    }

    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        String optionValues = "Sharpen Value: " + this.parameterValue;
        loggingService.addLog(fileName,"Sharpness", optionValues);
        return SharpenInterface.applySharpen(image,this.parameterValue);
    }
}