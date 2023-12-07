package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.baseEffects.*;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.*;

public class Inversion implements PhotoEffect{
    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService) {
        loggingService.addLog(fileName, "Inversion", "Standard");
        return InvertInterface.applyInvert(image);
    }
}
