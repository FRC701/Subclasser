// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "ArmMove.h"

class ArmMoveSub : public ArmMove {
 public:
  ArmMoveSub(Arm& arm);

  void Initialize() override;

  frc2::CommandPtr ToPtr() && override;

protected:
  double GetParam() override;

  std::unique_ptr<Command> TransferOwnership() && override;

  virtual std::unique_ptr<ArmMoveSub> make_unique();
};
