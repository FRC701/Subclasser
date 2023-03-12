// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include "commands/ArmMove.h"
#include "commands/ArmMoveSub.h"

RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
   frc::SmartDashboard::PutData("Arm Move", new ArmMove(mArm));
   frc::SmartDashboard::PutData("Arm Move Sub", new ArmMoveSub(mArm));

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

    frc2::Trigger([this] {
      return m_subsystem.ExampleCondition();
    }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

    // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
    // pressed, cancelling on release.
    // m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());

    button11.ToggleOnTrue(ArmMove(mArm).ToPtr());
    // button12.ToggleOnTrue(frc2::CommandPtr(std::make_unique<ArmMoveSub>(mArm)));
    // button12.ToggleOnTrue(&mArmMoveSubCommand);
    button12.ToggleOnTrue(ArmMoveSub(mArm).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
