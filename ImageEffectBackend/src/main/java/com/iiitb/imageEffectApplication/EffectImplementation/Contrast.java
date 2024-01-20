package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.BrightnessInterface;
import libraryInterfaces.ContrastInterface;
import libraryInterfaces.Pixel;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Contrast implements SingleValueParameterizableEffect{
    private float parameterValue;

    @Override
    public void setParameterValue(float parameterValue) throws IllegalParameterException {
        if(parameterValue>=0 && parameterValue<=200){
            this.parameterValue = parameterValue;
        }
        else throw new IllegalParameterException("Contrast takes only values between 0 to 200");
    }

    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        String optionValues = "Contrast Factor: " + ((this.parameterValue/100)+(float)0.5);
        loggingService.addLog(fileName,"Contrast", optionValues);
        return ContrastInterface.applyContrast(image,((this.parameterValue/100)+(float)0.5));
    }
}
