#pragma once

#include <frc/Spark.h>
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "Dash.h"

class Robot : public frc::TimedRobot {
 public:

  /*These "overrides" are the different functions (Perhaps call them hooks) 
   *that the robot looks for when it runs. Each one is run at different 
   *points during the robots operation.*/
  void RobotInit() override; //Runs *once* when the robot starts up
  void TeleopPeriodic() override; //Run when the robot is in teleop or the "user operated" portion of the competition
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void RobotPeriodic() override;

 private:
  //Drive system control is done throught the driveSystem object
  frc::DifferentialDrive* driveSystem;
  
  //Joystick obj that takes input from a controller so that we can move the robot around manually
  frc::Joystick* stick;

  //Drive system motors are only controlled through the SpeedController class, they *can* be set manually but shouldn't.
  frc::Spark leftDriveM{0};
  frc::Spark rightDriveM{1};

  //Motors are controlled through a speedController class, which can utilize PID control
  frc::SpeedControllerGroup* leftDriveT;
  frc::SpeedControllerGroup* rightDriveT;

  //Smartdashboard to view robot data
};
