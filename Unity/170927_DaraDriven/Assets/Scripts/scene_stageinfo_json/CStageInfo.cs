using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;

[Serializable]

public class CStageInfo
{
    public int id = 0;
    public int total_enemy_count = 0;
    public List<CUnitInfo> unit_info = null;
}
