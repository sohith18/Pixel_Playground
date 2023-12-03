package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.*;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.*;

public class Rotation implements SingleValueDiscreteEffect{
    private int parameterValue;

    @Override
    public void setParameterValue(int parameterValue) throws IllegalParameterException {
        if (parameterValue == 0 || parameterValue == 1 || parameterValue == 2 || parameterValue == 3)
        {
            this.parameterValue = parameterValue;
        }
        else throw new IllegalParameterException("Rotation can only take values 0, 1, 2 or 3");
    }

    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService) {
        String[] parameters = {"0", "90", "180", "270"};
        String optionValues = "Angle: " + parameters[parameterValue];

        loggingService.addLog(fileName, "Rotation", optionValues);
        return RotationInterface.applyRotation(image, parameterValue);
    }
}