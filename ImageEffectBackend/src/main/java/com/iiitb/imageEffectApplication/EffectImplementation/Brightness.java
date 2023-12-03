package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.BrightnessInterface;
import libraryInterfaces.Pixel;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Brightness implements SingleValueParameterizableEffect{
    private float parameterValue;

    @Override
    public void setParameterValue(float parameterValue) throws IllegalParameterException {
        if(parameterValue>=0 || parameterValue<=200){
            this.parameterValue = parameterValue;
        }
        else throw new IllegalParameterException("Brightness takes only values between 0 to 200");
    }

    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        String optionValues = "Brightness Value: " + this.parameterValue;

        loggingService.addLog(fileName,"Brightness", optionValues);
        return BrightnessInterface.applyBrightness(image,this.parameterValue);
    }
}