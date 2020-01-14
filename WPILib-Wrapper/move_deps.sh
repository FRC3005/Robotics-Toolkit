#! /bin/bash

BUILD_YEAR=2020
BUILD_REPO_DIR=./build/repos
RELEASE_DIR=$BUILD_REPO_DIR/releases/com/labview/frc
MOVE_DIR=C:/Users/Public/wpilib/$BUILD_YEAR/maven/com/labview/frc
VENDOR_DIR=C:/Users/Public/wpilib/$BUILD_YEAR/vendordeps

echo "*** Moving maven directories ***"
mkdir -p "$RELEASE_DIR/LabVIEW_WPILib_Extensions-cpp"
cp -r $RELEASE_DIR/LabVIEW_WPILib_Extensions-cpp $MOVE_DIR

echo "*** Moving vendor deps ***"
cp -r ./vendordeps/* $VENDOR_DIR
