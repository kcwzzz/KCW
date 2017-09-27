using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;
using UnityEngine.UI;
using System.Xml;

public class CRyuGameDataMgr
{
    private static CRyuGameDataMgr mInstance = null;

    public CAlberto PFAlberto = null;
    public CEnemy PFSlime = null;
    public CEnemy PFBobby = null;

    public int SceneLoadNum = 0;

    public int mLangType = 0;
    public List<string> mLangTextList = null;

    public Text mpTxtString = null;
    public CStageInfoList mStageInfoBundle= null;

    public void CreateRyu()
    {
        //load prefabs
        PFAlberto = Resources.Load<CAlberto>("Prefabs/PFAlberto");
        PFSlime = Resources.Load<CEnemy>("Prefabs/PFSlime");
        PFBobby = Resources.Load<CEnemy>("Prefabs/PFBobby");
        CreateWithLanguageType();
        mStageInfoBundle = new CStageInfoList();
        LoadStageXmlFile("XML/Enemy_info");

    }

    protected CRyuGameDataMgr()
    {
        mInstance = null;
    }
    public static CRyuGameDataMgr GetInst()
    {
        if (null == mInstance)
        {
            mInstance = new CRyuGameDataMgr();
        }

        return mInstance;
    }

    public void SetSceneNum(int tInt)
    {
        SceneLoadNum = tInt;
    }
    private void CreateWithLanguageType()
    {
        mLangTextList = new List<string>();

        if (SystemLanguage.Korean == Application.systemLanguage)
        {
            BuildLangType(0);
        }
        else if (SystemLanguage.English == Application.systemLanguage)
        {
            BuildLangType(1);
        }
    }
    public void BuildLangType(int tLangType)
    {
        mLangType = tLangType;

        int ti = 0;

        int tCount = mLangTextList.Count;

        for (ti = 0; ti < tCount; ti++)
        {
            mLangTextList[ti] = "";
        }
        mLangTextList.Clear();

        switch (mLangType)
        {
            case 0:
                {
                    LoadLangText("Lang/ui_ko");
                }
                break;

            case 1:
                {
                    LoadLangText("Lang/ui_en");
                }
                break;
        }

    }
    protected bool LoadLangText(string tFileName)
    {
        TextAsset tTextAsset = null;
        tTextAsset = Resources.Load<TextAsset>(tFileName) as TextAsset;

        if (null == tTextAsset)
        {
            return false;
        }
        else
        {
            Debug.Log(tTextAsset);
        }

        XmlDocument Doc = new XmlDocument();
        Doc.LoadXml(tTextAsset.text);

        XmlElement tElementRoot = Doc["ui_lang"];

        foreach (XmlElement tElementScene in tElementRoot.ChildNodes)
        {
            foreach (XmlElement tElementText in tElementScene.ChildNodes)
            {
                mLangTextList.Add(tElementText.InnerText);
            }
        }

        int ti = 0;
        int tCount = mLangTextList.Count;
        for (ti = 0; ti < tCount; ti++)
        {
            Debug.Log(mLangTextList[ti]);
        }

        return true;
    }

    protected bool LoadStageXmlFile(string tFileName)
    {
        TextAsset tTextAsset = null;
        tTextAsset = Resources.Load<TextAsset>(tFileName) as TextAsset;
        
        if (null == tTextAsset)
        {
            return false;
        }

        XmlDocument tDoc = new XmlDocument();
        tDoc.LoadXml(tTextAsset.text);

        CStageInfo tStageInfo = null;
        CUnitInfo tUnitINfo = null;

        XmlElement tElementRoot = tDoc["response"];

        mStageInfoBundle.mStageInfoList = new List<CStageInfo>();

        foreach (XmlElement tElementStageInfoList in tElementRoot.ChildNodes)
        {
            foreach (XmlElement tElementStageInfo in tElementStageInfoList.ChildNodes)
            {
                tStageInfo = null;
                tStageInfo = new CStageInfo();

                tStageInfo.mId = System.Convert.ToInt32(tElementStageInfo.ChildNodes[0].InnerText);
                tStageInfo.mEnemyCount = System.Convert.ToInt32(tElementStageInfo.ChildNodes[1].InnerText);

                if (tElementStageInfo.ChildNodes[2].ChildNodes.Count > 0)
                {
                    tStageInfo.mUnitInfoList = new List<CUnitInfo>();
                    foreach (XmlElement tElementUnitInfo in tElementStageInfo.ChildNodes[2])
                    {
                        tUnitINfo = null;
                        tUnitINfo = new CUnitInfo();

                        tUnitINfo.mX = System.Convert.ToInt32(tElementUnitInfo.ChildNodes[0].InnerText);
                        tUnitINfo.mY = System.Convert.ToInt32(tElementUnitInfo.ChildNodes[1].InnerText);
                        tUnitINfo.mZ = System.Convert.ToInt32(tElementUnitInfo.ChildNodes[2].InnerText);

                        tStageInfo.mUnitInfoList.Add(tUnitINfo);
                    }

                }
                mStageInfoBundle.mStageInfoList.Add(tStageInfo);

            }
        }

        foreach (CStageInfo tRyuStageINfo in this.mStageInfoBundle.mStageInfoList)
        {
            Debug.Log("stage_info id : " + tRyuStageINfo.mId.ToString());
            Debug.Log("stage_info total Enemy Count : " + tRyuStageINfo.mEnemyCount.ToString());

            foreach (CUnitInfo tRyuUnitInfo in tRyuStageINfo.mUnitInfoList)
            {
                Debug.Log("unit_info x: " + tRyuUnitInfo.mX.ToString());
                Debug.Log("unit_info y: " + tRyuUnitInfo.mY.ToString());

            }

            Debug.Log("---------------------------------");
        }

        return true;
    }





    void Start()
    {

    }

    void Update()
    {

    }
}
