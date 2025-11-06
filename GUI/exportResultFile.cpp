#include <map>
#include <vector>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>

using namespace std;

void exportResultFile(const map<char, map<char, double>>& ShortestPathGraph,
                      const map<char, double>& distances,
                      const map<char, char>& prev,
                      const vector<char>& shortest_path)
{
    QString appDir = QCoreApplication::applicationDirPath();

    QDir dir(appDir);

    dir.cdUp();
    dir.cdUp();
     dir.cdUp();
    if (!dir.cd("Visualization")) {
        QString visualizationPath = dir.filePath("Visualization");
        qDebug() << "Visualization folder not found. Creating:" << visualizationPath;
        if (!QDir().mkpath(visualizationPath)) {
            qDebug() << "Failed to create Visualization directory at" << visualizationPath;
            return;
        }
        if (!dir.cd("Visualization")) {
            return;
        }
    }

    QString filePath = dir.filePath("data.txt");
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return;
    }

    QTextStream outputFile(&file);

    outputFile << "        nodes = [";
    for (const auto& element : ShortestPathGraph) {
        // element.first is char; convert to QString safely
        outputFile << "\"" << QString(1, element.first) << "\",";
    }
    outputFile << "]\n";

    outputFile << "        edges = [\n";
    for (const auto& element : ShortestPathGraph) {
        for (const auto& i : element.second) {
            outputFile << "        (\"" << QString(1, element.first) << "\",\""
                       << QString(1, i.first) << "\"," << i.second << "),\n";
        }
    }
    outputFile << "        ]\n";

    outputFile << "        distances = {";
    for (const auto& dist : distances) {
        outputFile << "\"" << QString(1, dist.first) << "\":" << dist.second << ",";
    }
    outputFile << "}\n";

    outputFile << "        previous = {";
    for (const auto& element : prev) {
        outputFile << "\"" << QString(1, element.first) << "\":";
        if (element.second == 0) {
            outputFile << "None,";
        } else {
            outputFile << "\"" << QString(1, element.second) << "\",";
        }
    }
    outputFile << "}\n";

    outputFile << "        shortest_path = [";
    for (const auto& element : shortest_path) {
        outputFile << "\"" << QString(1, element) << "\",";
    }
    outputFile << "]\n";
    // positions = {
    //     "A": [-3, 1, 0],
    //     "B": [-1, 2, 0],
    //     "C": [1, 1, 0],
    // }
    outputFile << "        positions = {\"A\": [0, 0, 0],\"B\": [3, 0, 0],\"C\": [3, 4, 0]}";
    file.close();
}
