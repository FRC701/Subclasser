// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "commands/ArmMoveSub.h"

ArmMoveSub::ArmMoveSub(Arm& arm)
: ArmMove(arm)
{ }

// Called when the command is initially scheduled.
void ArmMoveSub::Initialize() {
  ArmMove::Initialize();
  std::cout << "ArmMoveSub::Initialize" << std::endl;
}

frc2::CommandPtr ArmMoveSub::ToPtr() && {
  return frc2::CommandPtr(make_unique());
}

std::unique_ptr<frc2::Command> ArmMoveSub::TransferOwnership() && {
  return make_unique();
}

double ArmMoveSub::GetParam()
{
  std::cout << "ArmMoveSub::GetParam" << std::endl;
  return 3.1415;
}

std::unique_ptr<ArmMoveSub> ArmMoveSub::make_unique() {
  return std::make_unique<ArmMoveSub>(*std::move(this));
}