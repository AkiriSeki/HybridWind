  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 0;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (generate_cartesian_pose_motio_P)
    ;%
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (generate_cartesian_pose_motio_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% generate_cartesian_pose_motio_B.GetInitialRobotState
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% generate_cartesian_pose_motio_B.GetDurationPeriod
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 16;
	
	  ;% generate_cartesian_pose_motio_B.Assignment1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 17;
	
	  ;% generate_cartesian_pose_motio_B.GetRobotState_o1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% generate_cartesian_pose_motio_B.GetRobotState_o2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 49;
	
	  ;% generate_cartesian_pose_motio_B.GetRobotState_o3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 65;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (generate_cartesian_pose_moti_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% generate_cartesian_pose_moti_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% generate_cartesian_pose_moti_DW.GetInitialRobotState_DWORK2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% generate_cartesian_pose_moti_DW.GetDurationPeriod_DWORK1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% generate_cartesian_pose_moti_DW.ApplyControl_DWORK1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% generate_cartesian_pose_moti_DW.ApplyControl_DWORK2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% generate_cartesian_pose_moti_DW.GetRobotState_DWORK1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% generate_cartesian_pose_moti_DW.ControlObjectiveScope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% generate_cartesian_pose_moti_DW.ControlCommandSuccessRate_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 779313999;
  targMap.checksum1 = 336140898;
  targMap.checksum2 = 2004420760;
  targMap.checksum3 = 3692368171;

