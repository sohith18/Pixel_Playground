package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;
import libraryInterfaces.SepiaInterface;

public class Sepia implements PhotoEffect {
    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName,"Sepia","-");
        return SepiaInterface.applySepia(image);
    }
}
