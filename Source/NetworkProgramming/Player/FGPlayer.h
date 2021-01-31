#pragma once

#include "GameFramework/Pawn.h"
#include "FGPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UFGMovementComponent;
class UStaticMeshComponent;
class USphereComponent;
class UFGPlayerSettings;
//class UFGNetDebugWidget;

UCLASS()
class NETWORKPROGRAMMING_API AFGPlayer : public APawn
{
	GENERATED_BODY()
private:
	float Forward = 0.0f;
	float Turn = 0.0f;

	float MovementVelocity = 0.0f;
	float Yaw = 0.0f;

	bool bBrake = false;

	FVector DesiredLocation = FVector::ZeroVector;

	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
		USphereComponent* CollisionComponent;
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleDefaultsOnly, Category = Camera)
		USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
		UCameraComponent* CameraComponent;
	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
		UFGMovementComponent* MovementComponent;

public:
	UPROPERTY(EditAnywhere, Category = PlayerSettings)
		UFGPlayerSettings* PlayerSettings;


public:
	AFGPlayer();

private:
	void Handle_Accelerate(float Value);
	void Handle_Turn(float Value);
	void Handle_BrakePressed();
	void Handle_BrakeReleased();

	void Handle_DebugMenuPressed();

	void CreateDebugWidget();

	//UPROPERTY(Transient)
		//UFGNetDebugWidget* DebugMenuInstance = nullptr;

	bool bShowDebugMenu = false;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
		bool IsBraking() const { return bBrake; }
	UFUNCTION(BlueprintPure)
		int32 GetPing() const;

	/*UPROPERTY(EditAnywhere, Category = Debug)
	TSubclassOf<UFGNetDebugWidget> DebugMenuClass;*/

	UFUNCTION(Server, Unreliable)
		void Server_SendLocation(const FVector& LocationToSend);

	UFUNCTION(NetMulticast, Unreliable)
		void Multicast_SendLocation(const FVector& LocationToSend);

	UFUNCTION(Server, Unreliable)
		void Server_SendFaceDirection(const float& LocationToSend);

	UFUNCTION(NetMulticast, Unreliable)
		void Multicast_SendFaceDirection(const float& LocationToSend);

	void ShowDebugMenu();
	void HideDebugMenu();

};