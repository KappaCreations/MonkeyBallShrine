// Fill out your copyright notice in the Description page of Project Settings.


#include "MyahmAgana.h"

// Sets default values
AMyahmAgana::AMyahmAgana()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	

	RootComponent = Mesh;



	Mesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void AMyahmAgana::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyahmAgana::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyahmAgana::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("RotFor", this, &AMyahmAgana::RotForward);
	InputComponent->BindAxis("RotHor", this, &AMyahmAgana::RotHorizontal);
	//InputComponent->BindAction("Jump", IE_Pressed, this, &AMyahmAgana::Jump);
	//InputComponent->BindAxis("CameraHorizontal", this, &AMyahmAgana::RotateCameraHorizontal);
}

void AMyahmAgana::RotForward(float value)
{
	AddActorLocalRotation(FRotator(0,value * rotSpeed,0));
}

void AMyahmAgana::RotHorizontal(float value)
{
	
	AddActorLocalRotation(FRotator(value*rotSpeed,0,0));
}

/*void AMyahmAgana::RotateCameraHorizontal(float value)
{
	FRotator newRotation = FRotator(value * rotSpeed, 0, 0);
	Mesh->AddRelativeRotation(newRotation, false, 0, ETeleportType::None);
}*/