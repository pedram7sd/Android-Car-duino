#include "sensordata.hpp"
#include "maneuver.hpp"

namespace Autodrive {
    namespace Overtaking {
        int usFront = SensorData::ultrasound.front;
        int objectDistance = 50;
        float overtaking = 0;

        command run(command lastCommand) {
            if (usFront > 0 && usFront < objectDistance) {
                if (overtaking < 1) overtaking = SensorData::encoderDistance();;
            }

            if (overtaking > 0) {
                lastCommand.setSpeed(slowSpeed);

                if ((SensorData::encoderDistance() - overtaking < 40)) {
                    lastCommand.setAngle(-1);
                }
            }

             return lastCommand;
        }
    }
}