package com.iiitb.imageEffectApplication.EffectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.ParameterizableEffect;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.*;

public class HueSaturation implements ParameterizableEffect {
    private float hueValue;
    private float saturationValue;
    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService) {
        String optionValues = "Hue: " + hueValue + ",Saturation: " + saturationValue;
        loggingService.addLog(fileName, "Hue-Saturation", optionValues);
        return HueSaturationInterface.applyHueSaturation(image, saturationValue, hueValue);
    }

    @Override
    public void setParameter(String paramName, float value) throws IllegalParameterException {
        if (paramName.equals("Hue"))
        {
            if (value >= 0 && value <= 100) hueValue = value;
            else throw new IllegalParameterException("Hue can only take values between 0 and 100");
        }
        else if (paramName.equals("Saturation"))
        {
            if (value >= 0 && value <= 100) saturationValue = value;
            else throw new IllegalParameterException("Saturation can only take values between 0 and 100");
        }
    }
}
