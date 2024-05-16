#include <ctime>
#include <iostream>
#include <valarray>

//#include "bitmap_image.h"
#include "BmpHandler.h"
#include "ImgProcessor.h"
#include "PathBuilder.h"
#include "PointSequencer.h"
#include "RobCodeGenerator.h"
#include "SegmentApproximator.h"
#include "SegmentSequencer.h"

#include <IProcessStep.h>
#include <LoadInputFileProcessStep.h>
#include <ProcessContext.h>


using namespace std;

enum RobCodeLang { KUKA };

int original_main();
int new_main();

int main()
{
    //original_main();
    new_main();

    return 0;
}

int new_main()
{
    // here, the process context variable is declared.
    // This is the variable that is used throughout the entire process.
    // It is passed from step to step. Each step is allowed to add or remove information from the context.
    kuka_generator::ProcessContext process_context;
    process_context.input_file = "resources\\path_01.csv";

    // create a vector into which all steps are inserted,
    // so all steps can be executed in the exact order using a for-loop
    std::vector<kuka_generator::IProcessStep*> steps;

    // create the LoadInputFileStep and insert it into the vector
    kuka_generator::LoadInputFileProcessStep load_input_file_process_step;
    steps.push_back(&load_input_file_process_step);

    // for-loop over all steps stored in the steps vector and execute each step passing in the process_context
    for (auto step : steps)
    {
        step->process(process_context);
    }
}

int original_main()
{
    //TODO: alte Bilder Löschen!
    clock_t start;
    start = clock();

    try
    {
        CBmpHandler bmpHandler("01_image.bmp");

        bmpHandler.image2Grayscale();
        bmpHandler.saveGrayscaleImage("02_gray.bmp");

        bmpHandler.image2Binary(100);
        bmpHandler.saveBinaryImage("03_binary.bmp");

        CImgProcessor imgProcessor(bmpHandler.getWidth(), bmpHandler.getHeight());
        imgProcessor.thinImage(bmpHandler.getBinaryArray());
        bmpHandler.drawOnBitmap(imgProcessor.getBinaryArrayThinned(), binary);
        bmpHandler.saveWorkingImage("04_thinOnBinary.bmp");

        CPointSequencer pointSequencer;
        pointSequencer.createSegments(imgProcessor.getBinaryArrayThinned(), bmpHandler.getWidth(), bmpHandler.getHeight());
        bmpHandler.drawOnBitmap(pointSequencer.getSegmentsVector(), binary, pixel);
        bmpHandler.saveWorkingImage("05_segmentsOnBinary.bmp");

        CSegmentApproximator segmentApproximator;
        segmentApproximator.approx(pointSequencer.getSegmentsVector(), 5.0);
        bmpHandler.drawOnBitmap(segmentApproximator.getSegmentsApproxVector(), working, lineConnect);
        bmpHandler.saveWorkingImage("06_segmentsApproxOnBinary.bmp");

        CSegmentSequencer segmentSequencer;
        segmentSequencer.sortSegments(segmentApproximator.getSegmentsApproxVector());
        bmpHandler.drawOnBitmap(segmentSequencer.getSegmentsSortedVector(), binary, lineConnect);
        bmpHandler.saveWorkingImage("07_segmentsSortedOnBinary.bmp");

        CPathBuilder pathBuilder;
        pathBuilder.createPath(segmentSequencer.getSegmentsSortedVector(), "08_path.csv");

        CRobCodeGenerator codeGenerator;
        codeGenerator.scaleX = 0.7;
        codeGenerator.scaleY = -0.7;
        codeGenerator.scaleZ = 50.0;
        codeGenerator.offsetX = 1000.0; // 1m in front of robot
        codeGenerator.offsetY = 0.0;
        codeGenerator.offsetZ = 750.0; // on top of a table with 0.75m height
        codeGenerator.generateRobCode(pathBuilder.getPath(), "09_robCode.src");


        float elapsed = (float)(clock() - start) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f\n", elapsed);
    }

    catch (exception& e)
    {
        cerr << e.what() << "\n";
    }

    system("pause");
}
