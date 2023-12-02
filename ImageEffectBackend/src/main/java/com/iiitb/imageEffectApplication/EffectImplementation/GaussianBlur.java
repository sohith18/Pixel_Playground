package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.GaussianBlurInterface;
import libraryInterfaces.Pixel;

public class GaussianBlur implements SingleValueParameterizableEffect {
    private float parameterValue;

    @Override
    public void setParameterValue(float parameterValue) throws IllegalParameterException{
        if(parameterValue<=50 && parameterValue>=0){
            this.parameterValue = parameterValue;
        }
        else throw new IllegalParameterException("Gaussian Blur takes only values between 0 to 50");
    }

    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        String optionValues = "Gaussian Blur Radius: " + this.parameterValue;
        loggingService.addLog(fileName,"Gaussian Blur",optionValues);
        return GaussianBlurInterface.applyGaussianBlur(image,this.parameterValue);
    }
}
