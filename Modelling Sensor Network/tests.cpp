#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

#include "TestSensor.h"
#include "LinearAdjuster.h"
#include "TableBasedAdjuster.h"
#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the adjustor classes. (12 points)
 */
void adjusterTests() {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using the test values given above as samples, assert that a
     * NullAdjustor's adjust method returns the argument's value
     * unchanged.
     */
    for(auto values:testValues)
    {
        assertTrue(NullAdjuster().adjust(values)==values,"failed");}

    /*
     * (2) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with a single breakpoint (0,0) returns
     * the same values as a NullAdjustor.
     */
    for(auto values:testValues)
    {
        assertTrue(TableBasedAdjuster().addBreakpoint(0, 0).adjust(values)==values,"failed");}

    /*
     * (3) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with breakpoints (-100,-110), (0,0)
     * and (100,90) returns the given expected values.
     *
     * Remember (from your basic C/C++ courses) that floating
     * point calculations do not always yield exact results
     * (rounding errors due to using the binary system).
     * Take this into account when checking the result.
     */
    float expected[] = { -11, -1.1, 0, 0.9, 9 };
    TableBasedAdjuster c1;
    c1.addBreakpoint(0,0);
    c1.addBreakpoint(-100,-110);
    c1.addBreakpoint(100,90);
    for(int i=0;i<5;i++)
    {
        assertTrue(c1.adjust(testValues[i] )== expected[i] , "failed");}


}

/**
 * Tests for the sensor classes. (12 points)
 */
void sensorTests () {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a NullAdjustor returns the raw
     * readings of a sensor as readings.
     */
    TestSensor testsensor("TestSensor",make_shared<NullAdjuster>());
    for(auto value:testValues)
    {
        testsensor.setRawReading(value);
        assertTrue(testsensor.reading()== value , "failed");
    }

    /*
     * (2) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a LinearAdjustor returns the
     * expected readings. Test with 10 differently configured
     * LinearAdjustors for each test value for exhaustive testing
     * (50 "assertTrue" invocations in total).
     */
    for(int i=0;i<10;i++)
    {
       int offset= i+1;
       int factor= i+1;

        LinearAdjuster linearadjuster(factor,offset);
        TestSensor testsensor("TestSensor",make_shared<LinearAdjuster>(linearadjuster));


        for(auto value:testValues)
        {
           auto expected = (value * factor + offset);
            testsensor.setRawReading(value);
            assertTrue(testsensor.reading()== expected , "failed");
        }
    }
}

/**
 * Tests for the sensor network. (16 points)
 */
void networkTests() {
    /*
     * Create a sensor network with 10 TestSensors named
     * "Thermometer n" (with n being the number of the thermometer)
     * that have their readings set to values 20 + n * 0.05.
     */
    SensorNetwork sensornetwork;
        for(int i=0;i<10;i++)
        {
            std::string name = "Thermometer" + std::to_string(i);
            TestSensor testsensor(name,make_shared<NullAdjuster>());
            testsensor.setRawReading(20 + i * 0.05);
            unique_ptr<Sensor> sensor= make_unique<TestSensor>(testsensor);
            sensornetwork.add(move(sensor));

        }

    /*
     * (1) Assert that adding a sensor with a name that is already
     * used by a sensor in the network throws a DuplicateSensorName
     * exception with the sensor's name as "what".
     */
        TestSensor testsensor("Thermometer11",make_shared<NullAdjuster>());
        unique_ptr<Sensor> sensor= make_unique<TestSensor>(testsensor);
        sensornetwork.add(move(sensor));

}

void allTests() {
    adjusterTests();
    sensorTests();
    networkTests();
}
