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

double ArmMoveSub::GetParam()
{
  std::cout << "ArmMoveSub::GetParam" << std::endl;
  return 3.1415;
}
