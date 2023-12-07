package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.*;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.*;

public class Flip implements SingleValueDiscreteEffect{
    private int p;


    public void setParameterValue(int p) throws IllegalParameterException {
        if (p == 0 || p == 1 || p == 2 || p == 3)
        {
            this.p = p;
        }
        else throw new IllegalParameterException("Flip can take values of 0, 1, 2, 3");}
    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService) {
        if(p==1){
            String optionValues = "Vertical flip";
            loggingService.addLog(fileName, "Flip", optionValues);
            return FlipInterface.applyFlip(image, 0,1);
        }
        if(p==2){
            String optionValues = "Horizontal flip";
            loggingService.addLog(fileName, "Flip", optionValues);
            return FlipInterface.applyFlip(image, 1,0);
        }
        if(p==3){
            String optionValues = "Both horizontal and vertical flip ";
            loggingService.addLog(fileName, "Flip", optionValues);
            return FlipInterface.applyFlip(image, 1,1);
        }
        String optionValues = "No flip";
        loggingService.addLog(fileName, "Flip", optionValues);
        return FlipInterface.applyFlip(image,0,0);
    }
}
