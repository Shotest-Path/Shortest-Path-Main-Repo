#include <map>
#include <vector>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <iomanip>
#include "generateTheCoordinates.h"
#include "pythonrunner.h"


using namespace std;

inline void exportResultFile(const map<char, map<char, double>>& ShortestPathGraph,
                      const map<char, double>& distances,
                      const map<char, char>& prev,
                      const vector<char>& shortest_path,
                             bool isShortest = true,
                        map<char ,pair<double,double>> thePoitsOfHoleGraph =  {}
                             )
{
    QString appdir = "C:/Users/Hp/OneDrive/Documents/4th Year/1st Term/Comp 411 Computational Geometry/Project/Visualization";

    QDir dir(appdir);

    if (!dir.exists()) {
        qDebug() << "Visualization folder not found. Creating:" << appdir;
        if (!QDir().mkpath(appdir)) {
            qDebug() << "Failed to create Visualization directory at" << appdir;
            return;
        }
    }

    QString filePath = dir.filePath("data.txt");
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return;
    }
    if(isConvexAndConcave==false)
    {
    QTextStream outputFile(&file);
    outputFile << "nodes = [";
    for (const auto& element : ShortestPathGraph) {
        // element.first is char; convert to QString safely
        outputFile << "\"" << QString(1, element.first) << "\",";
    }
    outputFile << "]\n";

    outputFile << "edges = [\n";
    for (const auto& element : ShortestPathGraph) {
        for (const auto& i : element.second) {
            outputFile << "        (\"" << QString(1, element.first) << "\",\""
                       << QString(1, i.first) << "\"," << i.second << "),\n";
        }
    }
    outputFile << "        ]\n";

    outputFile << "distances = {";
    for (const auto& dist : distances) {
        outputFile << "\"" << QString(1, dist.first) << "\":" << dist.second << ",";
    }
    outputFile << "}\n";

    outputFile << "previous = {";
    for (const auto& element : prev) {
        outputFile << "\"" << QString(1, element.first) << "\":";
        if (element.second == 0) {
            outputFile << "None,";
        } else {
            outputFile << "\"" << QString(1, element.second) << "\",";
        }
    }
    outputFile << "}\n";

    outputFile << "shortest_path = [";
    for (const auto& element : shortest_path) {
        outputFile << "\"" << QString(1, element) << "\",";
    }
    outputFile << "]\n";

    file.close();
}
    else if(isConvexAndConcave==true)
    {
        QTextStream outputFile(&file);
        outputFile << "nodes = [";
        for (const auto& element : ShortestPathGraph) {
            // element.first is char; convert to QString safely
            outputFile << "\"" << QString(1, element.first) << "\",";
        }
        outputFile << "]\n";

        outputFile << "edges = [\n";
        for (const auto& element : ShortestPathGraph) {
            for (const auto& i : element.second) {
                outputFile << "        (\"" << QString(1, element.first) << "\",\""
                           << QString(1, i.first) << "\"," <<  QString::number(i.second, 'f',1) << "),\n";
            }
        }
        outputFile << "        ]\n";

        outputFile << "distances = {";
        for (const auto& dist : distances) {
            outputFile << "\"" << QString(1, dist.first) << "\":" <<  QString::number(dist.second,'f',1) << ",";
        }
        outputFile << "}\n";

        outputFile << "previous = {";
        for (const auto& element : prev) {
            outputFile << "\"" << QString(1, element.first) << "\":";
            if (element.second == 0) {
                outputFile << "None,";
            } else {
                outputFile << "\"" << QString(1, element.second) << "\",";
            }
        }
        outputFile << "}\n";

        outputFile << "shortest_path = [";
        for (const auto& element : shortest_path) {
            outputFile << "\"" << QString(1, element) << "\",";
        }
        outputFile << "]\n";

        outputFile << "predefined_coordinates={\n";
        for (const auto& element : thePoitsOfHoleGraph) {
            outputFile << "        \"" << QString(1, element.first) << "\":np.array(["
                       << element.second.first << ", "
                       << element.second.second << ", 0]),\n";
        }
        outputFile << "        }\n";

        file.close();
    }
}
