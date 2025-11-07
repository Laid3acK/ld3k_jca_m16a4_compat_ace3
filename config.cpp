class CfgPatches
{
    class ld3k_jca_m16a4_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_M16A4",
            "Weapons_F_JCA_M16A4_Rifles_M16A4"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    class BulletBase;
    // JCA Bullets inherited from vanilla class B_556x45_Ball. To avoid all conflict with other mods, all JCA bullets with JCA as prefixe.
    // class B_556x45_Ball: BulletBase official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class JCA_B_556x45_Ball: BulletBase // M855, ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L117
    {
        ACE_caliber=5.70; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/223-rem-170406-en.pdf
        ACE_bulletLength=23.01; // ACE3
        ACE_bulletMass=4.018; // 62gr
        ACE_ammoTempMuzzleVelocityShifts[]={-26.55,-25.47,-22.85,-20.12,-16.98,-12.80,-7.64,-1.53,5.96,15.17,26.19}; // default ACE_ammoTempMuzzleVelocityShifts values (Ammo Temp MV Curve Tables by TiborasaurusRex). Muzzle velocity shift 0m/s 70°F (21°C), -8m/s 15°C
        ACE_ballisticCoefficients[]={0.149}; // US Army's Ballistic Research Laboratory ASM BC 0.151 converted to ICAO 0.149012
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=7;
        // ACE_barrelLengths[]={210.82,238.76,269.24,299.72,330.2,360.68,391.16,419.1,449.58,480.06,508,609.6}; // default ACE3 barrel lengths https://en.wikipedia.org/wiki/5.56%C3%9745mm_NATO
        // ACE_muzzleVelocities[]={723,764,796,825,843,866,878,892,906,915,922,900}; // default ACE3 MVs 4m https://en.wikipedia.org/wiki/5.56%C3%9745mm_NATO
        // ACE_muzzleVelocities[]={715,784,832,873,890,912,926,904}; // MVs V0 Strelok Pro 15°C
        // ACE_barrelLengths[]={203.2,254,304.8,368.3,406.4,457.2,508,609.6}; // 8", 10", 12", 14.5", 16", 18", 20", 24" barrels lengths
        ACE_muzzleVelocities[]={723,792,840,881,898,920,934}; // Muzzle Velocities 70°F (21°C) +8m/s, 791m/s (10.3"), 808m/s (11"), 873m/s (14.5"), 926m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        ACE_barrelLengths[]={203.2,254,304.8,368.3,406.4,457.2,508}; // M4A1 CQB, M4A4, M4A4 EGLM 10.3" (261.62mm), HK433 CQB 11" (279,4mm),  M4A1, M4A1 EGLM, HK433 14.5" (368.3mm), M16A4 20" (508mm) barrels lengths
        airLock=1;
        hit=9.12; // 1723 Joules, B_556x45_Ball 9 (1701 Joules)
        indirectHit=0;
        indirectHitRange=0;
        cost=1;
        typicalSpeed=926; // B_556x45_Ball 920
        airFriction=-0.00133644; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder, ACE3 0.00130094, B_556x45_Ball 0.0012
        waterFriction=-0.3;
        caliber=0.869565; // B_556x45_Ball, M995 AP3 52gr: 12mm RHA 100m MV 1030m/s https://www.nammo.com, effective perforation in-game 12mm RHA "armour_plate_12mm.bisurf" 100m ~900m/s: caliber ~0.9
        // M855: 1020 steel plate (Hardness=50/70 Rb; thickness=3mm) 570m (MV 910m/s), effective perforation in-game 3mm RHA "armour_plate_3mm.bisurf" 570m ~400m/s: caliber ~0.55
        model="\A3\Weapons_f\Data\bullettracer\tracer_white"; // B_762x51_Ball, B_556x45_Ball tracer_yellow
        tracerScale=1;
        tracerStartTime=0.17; // Visible 140m 600m (typically 800m) 4g MV 920m/s ICAO according to https://www.nammo.com,  ToF 140m 0.17s (Strelok Pro), B_556x45_Ball 0.05, https://www.nammo.com
        tracerEndTime=1.62; // Visible 140m 600m (typically 800m) 4g MV 920m/s ICAO according to https://www.nammo.com, ToF 800m 1.62s (Strelok Pro), B_556x45_Ball 1, https://www.nammo.com
        nvgOnly=0; // B_556x45_Ball w/o nvgOnly
        audibleFire=35;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        aiAmmoUsageFlags=64;
        class CamShakeExplode
        {
            power=2.23607;
            duration=0.4;
            frequency=20;
            distance=6.7082;
        };
        class CamShakeHit
        {
            power=5;
            duration=0.2;
            frequency=20;
            distance=1;
        };
    };
    class JCA_B_556x45_Ball_M855A1: JCA_B_556x45_Ball // M855A1 Lake City Army Ammunition Plant, 2022/23 article https://www.ar15.com/forums/AR-15/M855A1-Accuracy-and-Velocity-updated-/16-783286/
    {
        ACE_bulletLength=25.4; // 1"
        ACE_ballisticCoefficients[]={0.149}; // average ICAO G7 BC 0.149 from "Ballistic Performance of Rifle Bullets" by Bryan Litz, (average ICAO G1 BC 0.291)
        // 76°F (24°C rounded to 25°C for ACE3), 1019mB, 47%, barrel length 20": 3131fps (954m/s - 954m/s in-game), barrel length 14.5": average 2951fps (899m/s - 900m/s in-game) from 2022/23 article values https://www.ar15.com/forums/AR-15/M855A1-Accuracy-and-Velocity-updated-/16-783286/
        ACE_muzzleVelocities[]={734,804,853,894,911,934,948}; // Muzzle Velocities 70°F (21°C) +8m/s, 803m/s (10.3"), 821m/s (11"), 886m/s (14.5"), 940m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.39; // 1775 Joules
        typicalSpeed=940; // B_556x45_Ball 920
        airFriction=-0.00132981; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        caliber=1; // B_556x45_Ball 0.869565
    };
    class JCA_B_556x45_Ball_M193: JCA_B_556x45_Ball // M193 RUAG Ammotec AG
    {
        ACE_bulletLength=19; // average value
        ACE_bulletMass=3.6; // 55gr
        ACE_ballisticCoefficients[]={0.280}; // M193 RUAG Ammotec AG
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={772,846,898,941,960,983,998}; // Muzzle Velocities 70°F (21°C) +8m/s, 846m/s (10.3"), 864m/s (11"), 933m/s (14.5"), 990m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.33; // 1764 Joules
        typicalSpeed=990; // B_556x45_Ball 920
        airFriction=-0.00139457; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_556x45_Ball_Mk262: JCA_B_556x45_Ball // ACE_556x45_Ball_Mk262 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L141
    {
        ACE_bulletLength=25.25; // 0.994" Strelok Pro
        ACE_bulletMass=4.99; // 77gr
        ACE_ballisticCoefficients[]={0.356}; // ASM BC 0.361 converted to ICAO 0.356247
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={655,717,761,798,813,833,846}; // Muzzle Velocities 70°F (21°C) +8m/s, 716m/s (10.3"), 731m/s (11"), 790m/s (14.5"), 838m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.27; // 1752 Joules
        typicalSpeed=838; // B_556x45_Ball 920
        airFriction=-0.00114664; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_556x45_Ball_Mk318: JCA_B_556x45_Ball // ACE_556x45_Ball_Mk318 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L155
    {
        ACE_bulletLength=23.67; // Mod 1 0.932"
        ACE_bulletMass=4.018; // 62gr
        ACE_ballisticCoefficients[]={0.303}; // ASM BC 0.307 converted to ICAO 0.302958
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={742,812,862,904,921,944,958}; // Muzzle Velocities 70°F (21°C) +8m/s, 812m/s (10.3"), 829m/s (11"), 896m/s (14.5"), 950m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.59; // 1813 Joules
        typicalSpeed=950; // B_556x45_Ball 920
        airFriction=-0.00130202; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
    };
    class JCA_B_556x45_Ball_M995AP: JCA_B_556x45_Ball // ACE_556x45_Ball_M995_AP https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L168
    {
        ACE_bulletLength=22.7; // AP4, AP3 20.6
        ACE_bulletMass=4.536; // 70gr AP4, AP3 52gr
        ACE_ballisticCoefficients[]={0.306}; // ASM BC 0.310 converted to ICAO 0.305919
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={687,753,799,838,854,875,888}; // Muzzle Velocities 70°F (21°C) +8m/s, 752m/s (10.3"), 768m/s (11"), 830m/s (14.5"), 880m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        hit=9.3; // 1757 Joules
        typicalSpeed=880; // B_556x45_Ball 920
        airFriction=-0.00131582; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        caliber=1.2; // ACE_556x45_Ball_M995_AP 1.6, B_556x45_Ball 0.869565
        // M995 AP4 69gr: 7mm RHA 200m MV 900m/s https://www.nammo.com, effective perforation in-game 7mm RHA "armour_plate_7mm.bisurf" 200m ~700m/s: caliber ~0.7
        // M995 AP3 52gr: 12mm RHA 100m MV 1030m/s https://www.nammo.com, effective perforation in-game 12mm RHA "armour_plate_12mm.bisurf" 100m ~900m/s: caliber ~0.9
    };
    /*class B_556x45_dual: B_556x45_Ball // official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        cartridge="FxCartridge_65";
        audibleFire=20;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
        typicalSpeed=270;
        airFriction=-0.02;
        waterFriction=-0.01;
        effectFly="AmmoUnderwater";
        nvgOnly=1;
        aiAmmoUsageFlags="64 + 32";
    };*/
    class JCA_B_556x45_Ball_Dual: JCA_B_556x45_Ball // 5.56mm underwater subsonic DSG Technology https://dsgtec.com https://www.youtube.com/@DSGTechnology/videos https://www.thefirearmblog.com/blog/2017/04/20/dsg-technology-underwater-ammo
    {
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10 (Ammo Temp MV Curve Tables by TiborasaurusRex). Muzzle velocity shift 0m/s 70°F (21°C), -1m/s 15°C
        ACE_muzzleVelocities[]={220,241,255,268,273,280,284}; // Muzzle Velocities 70°F (21°C) +1m/s, 242m/s (10.3"), 247m/s (11"), 267m/s (14.5"), 283m/s (20") ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_M4/M16/HK433 initSpeed
        // cartridge="FxCartridge_65";
        visibleFire=1; // B_127x54_Ball, BulletBase 3
        audibleFire=5; // B_127x54_Ball, B_556x45_Ball 35, B_556x45_dual 20
        dangerRadiusBulletClose=4; // B_556x45_Ball 8
        dangerRadiusHit=8; // B_556x45_Ball 12
        suppressionRadiusBulletClose=2; // B_556x45_Ball 6
        suppressionRadiusHit=4; // B_556x45_Ball 8
        typicalSpeed=283; // B_556x45_dual 270
        airFriction=-0.0005713; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder, https://github.com/acemod/ACE3/pull/7982
        waterFriction=-0.01;
        effectFly="AmmoUnderwater";
        nvgOnly=1;
        aiAmmoUsageFlags="64 + 32";
    };
    class JCA_B_556x45_Ball_Tracer_Red: JCA_B_556x45_Ball
    {
        visibleFire=5; // B_556x45_Ball 3, B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5, BulletBase 3, BulletCore 16
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_556x45_Ball_Tracer_Green: JCA_B_556x45_Ball_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_556x45_Ball_Tracer_Yellow: JCA_B_556x45_Ball_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_B_556x45_Ball_IR_Dim_Tracer: JCA_B_556x45_Ball
    {
        tracerScale=0.5; // IR dim tracer, B_556x45_Ball 1
        tracerStartTime=0.01; // Visible 13m 600m (typically 950m) 3.9g MV 930m/s ICAO according to https://www.nammo.com, ToF 13m 0.01s (Strelok Pro), B_556x45_Ball 0.05
        tracerEndTime=2.12; // Visible 13m 600m (typically 950m) 3.9g MV 930m/s ICAO according to https://www.nammo.com, ToF 950m 2.12s (Strelok Pro), B_556x45_Ball 1
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    // JCA 5.56x45 Stanag Magazines use vanilla class 30Rnd_556x45_Stanag. To avoid all conflict with other mods and RPT Updating base class, all JCA 5.56x45 Stanag Magazines with JCA as prefixe
    /*class 30Rnd_556x45_Stanag: CA_Magazine official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        picture="\a3\Weapons_F\MagazineProxies\data\UI\icon_30Rnd_556x45_Stanag_CA.paa";
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag0";
        ammo="B_556x45_Ball";
        count=30;
        initSpeed=920;
        tracersEvery=0;
        lastRoundsTracer=4;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag1";
        modelSpecial="\a3\Weapons_F_Exp\MagazineProxies\mag_556x45_stanag_30rnd.p3d";
        modelSpecialIsProxy=1;
    };
    class 30Rnd_556x45_Stanag: CA_Magazine // JCA default config
    {
        author="Grave";
        scope=2;
        displayName="5.56 mm 30Rnd Mag";
        picture="\weapons_f_JCA_M16A4\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_CA.paa";
        modelSpecial="weapons_f_JCA_M16A4\MagazineProxies\30Rnd_556_SMAG.p3d";
        modelSpecialIsProxy=1;
        ammo="B_556x45_Ball";
        count=30;
        mass=8;
        initSpeed=920;
        tracersEvery=0;
        lastRoundsTracer=0;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag1";
    };*/
    class JCA_30Rnd_556x45_Stanag: CA_Magazine // JCA default config with JCA as prefixe
    {
        picture="\weapons_f_JCA_M16A4\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_CA.paa";
        author="Grave";
        scope=2;
        displayName="5.56 mm 30Rnd Mag";
        ammo="JCA_B_556x45_Ball";
        count=30;
        mass=8; // 13.6 Steel magazine 30 rounds (empty) 250g + 30x 12.3g (M855 cartridge weight), 30Rnd_556x45_Stanag 8
        initSpeed=926; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        tracersEvery=0;
        lastRoundsTracer=0;
        descriptionShort="Caliber: 5.56x45 mm<br />Rounds: 30<br />Used in: 5.56 STANAG Rifles";
        modelSpecial="weapons_f_JCA_M16A4\MagazineProxies\30Rnd_556_SMAG.p3d";
        modelSpecialIsProxy=1;
    };
    class JCA_30Rnd_556x45_Stanag_M855A1: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd M855A1 Mag";
        ammo="JCA_B_556x45_Ball_M855A1";
        initSpeed=940; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M855A1";
    };
    class JCA_30Rnd_556x45_Stanag_M193: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd M193 Mag";
        ammo="JCA_B_556x45_Ball_M193";
        mass=7.8; // 13.2 Steel magazine 30 rounds (empty) 250g + 30x 11.6g (M193 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=990; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M193";
    };
    class JCA_30Rnd_556x45_Stanag_Mk262: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Mk262 Mag";
        ammo="JCA_B_556x45_Ball_Mk262";
        mass=8.4; // 14.3 Steel magazine 30 rounds (empty) 250g + 30x 13.3g (Mk262 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=838; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk262";
    };
    class JCA_30Rnd_556x45_Stanag_Mk318: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Mk318 Mag";
        ammo="JCA_B_556x45_Ball_Mk318";
        initSpeed=950; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk318";
    };
    class JCA_30Rnd_556x45_Stanag_M995AP: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd M995 AP Mag";
        ammo="JCA_B_556x45_Ball_M995AP";
        mass=8.1; // 13.8 Steel magazine 30 rounds (empty) 250g + 30x 12.6g (M995 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=880; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M995 AP";
    };
    class JCA_30Rnd_556x45_Stanag_UW: JCA_30Rnd_556x45_Stanag // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Dual Purpose Mag";
        ammo="JCA_B_556x45_Ball_Dual";
        initSpeed=283; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="UW";
    };
    class JCA_30Rnd_556x45_Stanag_Red: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Red) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_556x45_Stanag_Green: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Green) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Yellow: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Yellow) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_IR: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (IR) Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Red: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Red) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Green: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Green) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Yellow: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Yellow) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_IR: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (IR) Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_30Rnd_556x45_Stanag_Sand: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Sand Mag";
        picture="\weapons_f_JCA_M16A4\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_sand_CA.paa";
        hiddenSelections[]=
        {
            "Camo"
        };
        hiddenSelectionsTextures[]=
        {
            "weapons_f_JCA_M16A4\MagazineProxies\data\mag_30Rnd_556_SMAG_sand_CO.paa"
        };
    };
    class JCA_30Rnd_556x45_Stanag_Sand_M855A1: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd M855A1 Sand Mag";
        ammo="JCA_B_556x45_Ball_M855A1";
        initSpeed=940; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M855A1";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_M193: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd M193 Sand Mag";
        ammo="JCA_B_556x45_Ball_M193";
        mass=7.8; // 13.2 Steel magazine 30 rounds (empty) 250g + 30x 11.6g (M193 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=990; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M193";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Mk262: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Mk262 Sand Mag";
        ammo="JCA_B_556x45_Ball_Mk262";
        mass=8.4; // 14.3 Steel magazine 30 rounds (empty) 250g + 30x 13.3g (Mk262 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=838; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk262";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Mk318: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Mk318 Sand Mag";
        ammo="JCA_B_556x45_Ball_Mk318";
        initSpeed=950; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="Mk318";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_M995AP: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd M995 AP Sand Mag";
        ammo="JCA_B_556x45_Ball_M995AP";
        mass=8.1; // 13.8 Steel magazine 30 rounds (empty) 250g + 30x 12.6g (M995 cartridge weight), 30Rnd_556x45_Stanag 8, JCA 8
        initSpeed=880; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="M995 AP";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_UW: JCA_30Rnd_556x45_Stanag_Sand // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Dual Purpose Sand Mag";
        ammo="JCA_B_556x45_Ball_Dual";
        initSpeed=283; // according to ACE_muzzleVelocities M16A4 20" (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
        displaynameshort="UW";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Red: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Red) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Green: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Green) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Yellow: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Yellow) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_IR: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (IR) Sand Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Red) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Green) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Yellow) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (IR) Sand Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
};
class CfgMagazineWells
{
    class STANAG_556x45
    {
        BI_Magazines[]= // JCA default config with 5.56x45mm JCA Mags
        /*{
            "30Rnd_556x45_Stanag",
            "30Rnd_556x45_Stanag_Red",
            "30Rnd_556x45_Stanag_Green",
            "30Rnd_556x45_Stanag_Yellow",
            "30Rnd_556x45_Stanag_IR",
            "30Rnd_556x45_Stanag_Tracer_Red",
            "30Rnd_556x45_Stanag_Tracer_Green",
            "30Rnd_556x45_Stanag_Tracer_Yellow",
            "30Rnd_556x45_Stanag_Tracer_IR",
            "30Rnd_556x45_Stanag_Sand",
            "30Rnd_556x45_Stanag_Sand_Red",
            "30Rnd_556x45_Stanag_Sand_Green",
            "30Rnd_556x45_Stanag_Sand_Yellow",
            "30Rnd_556x45_Stanag_Sand_IR",
            "30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "30Rnd_556x45_Stanag_Sand_Tracer_IR"
        };*/
        { // 5.56x45mm default Arma3 Mags official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
            "30Rnd_556x45_Stanag",
            "30Rnd_556x45_Stanag_green",
            "30Rnd_556x45_Stanag_red",
            "30Rnd_556x45_Stanag_Tracer_Red",
            "30Rnd_556x45_Stanag_Tracer_Green",
            "30Rnd_556x45_Stanag_Tracer_Yellow",
            "30Rnd_556x45_Stanag_Sand",
            "30Rnd_556x45_Stanag_Sand_green",
            "30Rnd_556x45_Stanag_Sand_red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "30Rnd_556x45_Stanag_Sand_Tracer_Yellow"
        };
        JCA_Magazines[]= // Weapon initSpeed -1 with ACE_barrelLength 508mm (20"): 926, 940, 990, 838, 950, 880, 283m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_30Rnd_556x45 magazines initSpeed
        { // All 5.56x45mm JCA Mags
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW"
        };
    };
};
class Mode_SemiAuto;
class Mode_Burst;
class CfgWeapons
{
    class InventoryMuzzleItem_Base_F;
    class ItemCore;
    class Rifle;
    class Rifle_Base_F: Rifle
    {
        class WeaponSlotsInfo;
    };
    class JCA_arifle_M16A4_base_F: Rifle_Base_F
    {
        ACE_barrelTwist=177.8; // 1:7"
        ACE_barrelLength=508; // 20"
        ACE_railHeightAboveBore=2.42081; // ACE3 checkScopes.sqf
        maxZeroing=1100; // distance 5.56x45 Mk262 Mach 0.8 (272m/s) ICAO, Assault rifles 5.56x45 800, JCA 800
        initSpeed=-1; // 926, 940, 990, 838, 950, 880, 283m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 880
        canShootInWater=1; // SDAR_base_F
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=87.9; // https://fnamerica.com/products/rifles/fn-m16a4/, JCA 85
        };
        class Single: Mode_SemiAuto
        {
            class BaseSoundModeType
            {
            };
            class StandardSound: BaseSoundModeType // SDAR_base_F
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            class SilencedSound: BaseSoundModeType
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            dispersion=0.000494; // 3.02 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755,JCA 0.00058 (1.99 MOA)
        };
        class Burst: Mode_Burst
        {
            class BaseSoundModeType
            {
            };
            class StandardSound: BaseSoundModeType // SDAR_base_F
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            class SilencedSound: BaseSoundModeType
            {
                beginwater1[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_01",
                    1,
                    1,
                    400
                };
                beginwater2[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_02",
                    1,
                    1,
                    400
                };
                beginwater3[]=
                {
                    "A3\Sounds_F\arsenal\weapons\Rifles\SDAR\underwater_sdar_03",
                    1,
                    1,
                    400
                };
                soundBeginWater[]=
                {
                    "beginwater1",
                    0.33,
                    "beginwater2",
                    0.33,
                    "beginwater3",
                    0.34
                };
            };
            dispersion=0.000494; // 3.02 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755,JCA 0.00087 (2.99 MOA)
        };
    };
    class JCA_arifle_M16A4_FG_base_F: JCA_arifle_M16A4_base_F
    {
        initSpeed=-1; // 926, 940, 990, 838, 950, 880, 283m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=87.9; // https://fnamerica.com/products/rifles/fn-m16a4/, JCA 85
        };
    };
    class JCA_arifle_M16A4_GL_base_F: JCA_arifle_M16A4_base_F
    {
        initSpeed=-1; // 926, 940, 990, 838, 950, 880, 283m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        descriptionShort="Assault Rifle<br />Caliber: 5.56x45 mm<br />Grenade Launcher<br />Caliber: 40 mm";
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=117.9; // M203 1.36kg https://en.wikipedia.org/wiki/M203_grenade_launcher, JCA 105
        };
    };
    class JCA_arifle_M16A4_sand_F: JCA_arifle_M16A4_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_M16A4_FG_sand_F: JCA_arifle_M16A4_FG_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_M16A4_GL_sand_F: JCA_arifle_M16A4_GL_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_M855A1",
            "JCA_30Rnd_556x45_Stanag_Sand_M193",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk262",
            "JCA_30Rnd_556x45_Stanag_Sand_Mk318",
            "JCA_30Rnd_556x45_Stanag_Sand_M995AP",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_M855A1",
            "JCA_30Rnd_556x45_Stanag_M193",
            "JCA_30Rnd_556x45_Stanag_Mk262",
            "JCA_30Rnd_556x45_Stanag_Mk318",
            "JCA_30Rnd_556x45_Stanag_M995AP",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class muzzle_snds_H: ItemCore // Sound Suppressor 6.5mm
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class muzzle_snds_M: muzzle_snds_H // Sound Suppressor 5.56mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=8;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_M 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_M 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.1;
    };
};
