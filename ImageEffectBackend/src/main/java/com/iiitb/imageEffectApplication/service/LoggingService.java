package com.iiitb.imageEffectApplication.service;
import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

@Service
public class LoggingService {

    private String logFileName = "logs.txt";

    public void addLog(String fileName, String effectName, String optionValues) {
        File logFile = new File(logFileName);

        LocalDateTime myDateObj = LocalDateTime.now();
        DateTimeFormatter format = DateTimeFormatter.ofPattern("MM-dd-yyyy HH:mm:ss");
        String timestamp = myDateObj.format(format);

        if (logFile.exists())
        {
            try (FileWriter writer = new FileWriter(logFileName, true)) {
                writer.append(timestamp + "," + fileName + "," + effectName + "," + optionValues + "\n");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        else
        {
            try {
                logFile.createNewFile();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            try (FileWriter writer = new FileWriter(logFileName, true)) {
                writer.write(timestamp + "," + fileName + "," + effectName + "," + optionValues + "\n");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public List<LogModel> getAllLogs() {
        File logFile = new File(logFileName);

        ArrayList<LogModel> logs = new ArrayList<LogModel>();

        if (logFile.exists())
        {
            try (Scanner scanner = new Scanner(logFile)) {
                while (scanner.hasNextLine()) {
                    String log = scanner.nextLine();
                    String[] fieldValues = log.split(",");

                    LogModel logObj = new LogModel(fieldValues[0], fieldValues[1], fieldValues[2], fieldValues[3]);

                    logs.add(logObj);
                }
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
        return logs;
    }

    public List<LogModel> getLogsByEffect(String effectName) {
        File logFile = new File(logFileName);

        ArrayList<LogModel> logsByEffect = new ArrayList<LogModel>();

        if (logFile.exists())
        {
            try (Scanner scanner = new Scanner(logFile)) {
                while (scanner.hasNextLine()) {
                    String log = scanner.nextLine();
                    String[] fieldValues = log.split(",");

                    // fieldValues[2].equalsIgnoreCase(effectName)

                    if (fieldValues[2].toLowerCase().startsWith(effectName.toLowerCase())) {
                        LogModel logObj = new LogModel(fieldValues[0], fieldValues[1], fieldValues[2], fieldValues[3]);
                        logsByEffect.add(logObj);
                    }
                }
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
        return logsByEffect;
    }

    public void clearLogs() {
        File logFile = new File(logFileName);

        if (logFile.exists())
        {
            logFile.delete();
        }
    }
}
