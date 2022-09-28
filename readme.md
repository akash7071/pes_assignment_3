## Multiple Sample Approach to Refine Touch Sensing

Multiple samples are collected each poll and the samples are ranked 
to find the touch position sample which has occured most times along with noise values.
In this case 25 samples are being collected which introduces some delay of its own. 
This 500ms delay between blinks is compensated by reducing it by an offset.

Even after all the caliberation and filtering, there are still many outliers which trigger
the wrong LED color here and there. In my testing with a few boards and couple of environment(humidity and static) I have 
found success rate of anywhere from **70%-85%** .

----------------------------------------------------------------------------------------------------------------------------
There is a **Debug mode** and a **Run mode**. Debug mode uses the Semihost to print out diagnostic data.
Since I'm collecting multiple samples and deciding on the collective information, I am not printing all the samples.
It is possible to print one valid sample by configuring SAMPLE_TO_LOG in touch_compute.h

**In case the specific sample chosen to be logged turns out to be NOISE, it wont be printed. 
Please try changing LED color and sample chosen to log, to see valid debug output of touch sample values.**

All the parameters like POLL_INTERVAL, NUM_SAMPLES and more operational parameters are configureable from their

respective header files and declarations.


Review Points:

To be received
