/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Spark.h>
#include <frc/Joystick.h>
#include <frc/SpeedControllerGroup.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  //Drive system control is done throught the driveSystem object
  frc::DifferentialDrive* driveSystem;
  
  //Drive system motors are only controlled through the SpeedController class, they *can* be set manually but shouldn't.
  frc::Spark* leftDriveM;
  frc::Spark* rightDriveM;

  //Motors are controlled through a speedController class, which can utilize PID control
  frc::SpeedControllerGroup* leftDriveT;
  frc::SpeedControllerGroup* rightDriveT;


};
