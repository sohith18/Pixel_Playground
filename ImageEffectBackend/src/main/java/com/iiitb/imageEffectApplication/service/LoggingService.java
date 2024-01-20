package com.iiitb.imageEffectApplication.service;
import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

@Service
public class LoggingService {

    private final String logFileName = "logs.txt";

    public void addLog(String fileName, String effectName, String optionValues) {
        File logFile = new File(logFileName);

        // Get Timestamp with current date and time
        LocalDateTime myDateObj = LocalDateTime.now();
        DateTimeFormatter format = DateTimeFormatter.ofPattern("MM-dd-yyyy HH:mm:ss");
        String timestamp = myDateObj.format(format);

        if (logFile.exists())
        {
            // Write to the file
            try (FileWriter writer = new FileWriter(logFileName, true)) {
                writer.append(timestamp + "," + fileName + "," + effectName + "," + optionValues + "\n");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        else
        {
            // Create new file
            try {
                logFile.createNewFile();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            // Write to the file
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
            // Read from file
            try (Scanner scanner = new Scanner(logFile)) {
                while (scanner.hasNextLine()) {
                    String log = scanner.nextLine();
                    String[] fieldValues = log.split(",");

                    // Create Log object
                    LogModel logObj = new LogModel(fieldValues[0], fieldValues[1], fieldValues[2], fieldValues[3]);

                    logs.add(logObj);
                }
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }

        Collections.reverse(logs);
        return logs;
    }

    public List<LogModel> getLogsByEffect(String effectName) {
        File logFile = new File(logFileName);

        ArrayList<LogModel> logsByEffect = new ArrayList<LogModel>();

        if (logFile.exists())
        {
            // Read from file
            try (Scanner scanner = new Scanner(logFile)) {
                while (scanner.hasNextLine()) {
                    String log = scanner.nextLine();
                    String[] fieldValues = log.split(",");

                    // Check if the effect matches with given effect name
                    if (fieldValues[2].toLowerCase().startsWith(effectName.toLowerCase())) {
                        // Create Log object
                        LogModel logObj = new LogModel(fieldValues[0], fieldValues[1], fieldValues[2], fieldValues[3]);
                        logsByEffect.add(logObj);
                    }
                }
            } catch (FileNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
        Collections.reverse(logsByEffect);
        return logsByEffect;
    }

    public void clearLogs() {
        File logFile = new File(logFileName);

        if (logFile.exists())
        {
            // Delete the file
            logFile.delete();
        }
    }
}
