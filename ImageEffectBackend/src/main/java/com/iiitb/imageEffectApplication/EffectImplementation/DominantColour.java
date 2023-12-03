package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.DominantColourInterface;
import libraryInterfaces.Pixel;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DominantColour implements PhotoEffect {
    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService) {
        loggingService.addLog(fileName, "Dominant Colour", "-");
        return DominantColourInterface.applyDominantColour(image);
    }
}
