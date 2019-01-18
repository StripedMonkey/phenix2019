#include "Robot.h"

void Robot::RobotInit() {
    /*Control the robot through these two objects, one is the wheels the other *
    * is the joystick that the user utilizes. Together they represent the input*
    *(joystick) and the robot.                                                 */
    driveSystem = new frc::DifferentialDrive{*leftDriveT, *rightDriveT};
    stick = new frc::Joystick{0};

    //Drive system motors are only controlled through the SpeedController class, they *can* be set manually but shouldn't.
    leftDriveM = new frc::Spark{0};
    rightDriveM = new frc::Spark{1};

    
    //Motors are controlled through a speedController class, which can utilize PID control
    leftDriveT = new frc::SpeedControllerGroup{*leftDriveM};
    rightDriveT = new frc::SpeedControllerGroup{*rightDriveM};
}

void Robot::TeleopPeriodic() {
    driveSystem->ArcadeDrive(stick->GetThrottle(), stick->GetY());
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
