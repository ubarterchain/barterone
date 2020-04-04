#include <chainparams.h>
#include <consensus/merkle.h>
#include <tinyformat.h>
#include <util.h>
#include <utilstrencodings.h>
#include <assert.h>
#include <chainparamsseeds.h>
/*                                       To create a new blockchain need to change below 17+ places those marked with //--// using this generated 6 values.
generator 046BEF7F292BC287D5FFBE986F74FA77E59824E1A8908AD7DB7F5E02366776657A1F48EE4F959FF63B187B1B05C069BD89682A25A1A63EF0498FEA4025E095568D "The EasiestBC will bring the world more fair and hope! 04/03/2020" 486604799
Merkle Hash:    Byteswapped: c12cf330cc87a373cbf89bda4e160d27a7d1cb42a380385a4542e6baf13340a1
Hash: 00000000c169e628ecaf7f1ae833aba5bdb634491d1e57f587aa9088ec2133b4                                 Nonce: 1296058089               Unix time: 1585917209*/
static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward){
    CMutableTransaction txNew;    txNew.nVersion = 1;    txNew.vin.resize(1);    txNew.vout.resize(1);    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));		
    txNew.vout[0].nValue = genesisReward;    txNew.vout[0].scriptPubKey = genesisOutputScript;    CBlock genesis;    genesis.nTime    = nTime;    genesis.nBits    = nBits;    genesis.nNonce   = nNonce;    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));    genesis.hashPrevBlock.SetNull();    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);    return genesis;                              }
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward){   
    const char* pszTimestamp = "The EasiestBC will bring the world more fair and hope! 04/03/2020";                             //--// need put in new pszTimestamp
                                                                                                                                //--// need put in new public address - 130 Characters
    const CScript genesisOutputScript = CScript() << ParseHex("046BEF7F292BC287D5FFBE986F74FA77E59824E1A8908AD7DB7F5E02366776657A1F48EE4F959FF63B187B1B05C069BD89682A25A1A63EF0498FEA4025E095568D") << OP_CHECKSIG;//--//
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);                  }
void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout){    consensus.vDeployments[d].nStartTime = nStartTime;          consensus.vDeployments[d].nTimeout = nTimeout;  }

class CMainParams : public CChainParams {/** * Main network */
public:
    CMainParams() {
        strNetworkID = "main";        consensus.nSubsidyHalvingInterval = 2100000;             consensus.powLimit = uint256S("00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff");                                                  
        consensus.nPowTargetTimespan = 24 * 60 * 60;          consensus.nPowTargetSpacing = 10 * 60;        consensus.fPowAllowMinDifficultyBlocks = false;        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 136;        consensus.nMinerConfirmationWindow = 144;         consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601;         consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; 
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1462060800;         consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1493596800; 
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1479168000;         consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1510704000;
        consensus.nMinimumChainWork = uint256S("0x00");          consensus.defaultAssumeValid = uint256S("0x00");         pchMessageStart[0] = 0xa2;           pchMessageStart[1] = 0xb4;           pchMessageStart[2] = 0xc6;          pchMessageStart[3] = 0xd8;           nDefaultPort = 9567;                 nPruneAfterHeight = 100000; 
        genesis = CreateGenesisBlock(1585917209, 1296058089, 0x1d00ffff, 1, 1 * COIN);                                            //--// need to put in new Unix time 1585917209, Nonce 1296058089,
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00000000c169e628ecaf7f1ae833aba5bdb634491d1e57f587aa9088ec2133b4"));     //--// need to put in new hash of genesis block
        assert(genesis.hashMerkleRoot == uint256S("0xc12cf330cc87a373cbf89bda4e160d27a7d1cb42a380385a4542e6baf13340a1"));         //--// need to put in new hash of genesis block merkle root -Byteswapped.
        vFixedSeeds.clear();                 vSeeds.clear();           base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,0);          base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);           base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,128);           
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};     	bech32_hrp = "eb";        fDefaultConsistencyChecks = false;        fRequireStandard = true;        fMineBlocksOnDemand = false;
        checkpointData = {{{ 0, uint256S("0x00000000c169e628ecaf7f1ae833aba5bdb634491d1e57f587aa9088ec2133b4")},}};               //--//  need to put in new hash of genesis block
        chainTxData = ChainTxData{
            1585917209,                                                                                                           //--// * UNIX timestamp for genesis block (need to put)   new Unix time 
            0,       
            0         };    }     };

class CTestNetParams : public CChainParams {            /** * Testnet (v3) */
public:
    CTestNetParams() {
        strNetworkID = "test";        consensus.nSubsidyHalvingInterval = 210000;               consensus.BIP16Height = 514;                              consensus.BIP34Height = 21111;
        consensus.BIP34Hash = uint256S("0x0000000023b3a96d3484e5abb3755c413e7d41500f8e2a5c3f0dd01299cd8ef8");        consensus.BIP65Height = 581885;                          consensus.BIP66Height = 330776; 
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");         consensus.nPowTargetTimespan = 14 * 24 * 60 * 60;          consensus.nPowTargetSpacing = 10 * 60;                    consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;                       consensus.nRuleChangeActivationThreshold = 1512;          consensus.nMinerConfirmationWindow = 2016;  
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601;          consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999;  
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 1456790400;          consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = 1493596800;  
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = 1462060800;         consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = 1493596800; 
        consensus.nMinimumChainWork = uint256S("0x00");          consensus.defaultAssumeValid = uint256S("0x00");      	pchMessageStart[0] = 0x2a;                         pchMessageStart[1] = 0x4b;               pchMessageStart[2] = 0x6c;                 pchMessageStart[3] = 0x8d;                
	    nDefaultPort = 19567;                              nPruneAfterHeight = 1000;
    	genesis = CreateGenesisBlock(1585917209, 1296058089, 0x1d00ffff, 1, 1 * COIN);                                            //--// need to put in new Unix time 1585917209, Nonce 1296058089,
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00000000c169e628ecaf7f1ae833aba5bdb634491d1e57f587aa9088ec2133b4"));     //--// need to put in new hash of genesis block
        assert(genesis.hashMerkleRoot == uint256S("0xc12cf330cc87a373cbf89bda4e160d27a7d1cb42a380385a4542e6baf13340a1"));         //--// need to put in new hash of genesis block merkle root
        vFixedSeeds.clear();          vSeeds.clear();        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};                 base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};	    bech32_hrp = "ebt";        fDefaultConsistencyChecks = false;                fRequireStandard = false;                  fMineBlocksOnDemand = false;
        checkpointData = {{	{ 0, uint256S("0x00000000c169e628ecaf7f1ae833aba5bdb634491d1e57f587aa9088ec2133b4")},}};              //--// need to put in new hash of genesis block            
        chainTxData = ChainTxData{
            1577032012,                                                                                                           //--// need to put in new Unix time 1585917209
            0,       
            0   };    }          };

class CRegTestParams : public CChainParams {              /** * Regression test */
public:
    CRegTestParams() {
        strNetworkID = "regtest";        consensus.nSubsidyHalvingInterval = 150;        consensus.BIP16Height = 0;                consensus.BIP34Height = 100000000;         consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1351;            consensus.BIP66Height = 1251;          consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60;         consensus.nPowTargetSpacing = 10 * 60;        consensus.fPowAllowMinDifficultyBlocks = true;        consensus.fPowNoRetargeting = true;        consensus.nRuleChangeActivationThreshold = 108;         consensus.nMinerConfirmationWindow = 144;       
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;        consensus.nMinimumChainWork = uint256S("0x00");                consensus.defaultAssumeValid = uint256S("0x00");
	    pchMessageStart[0] = 0xab;                       pchMessageStart[1] = 0xbc;            pchMessageStart[2] = 0xcd;                pchMessageStart[3] = 0xde;          	nDefaultPort = 19678;                                     nPruneAfterHeight = 1000;
    	genesis = CreateGenesisBlock(1585917209, 1296058089, 0x1d00ffff, 1, 1 * COIN);                                            //--// need to put in new Unix time, Nonce
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00000000c169e628ecaf7f1ae833aba5bdb634491d1e57f587aa9088ec2133b4"));     //--// need to put in new hash of genesis block
        assert(genesis.hashMerkleRoot == uint256S("0xc12cf330cc87a373cbf89bda4e160d27a7d1cb42a380385a4542e6baf13340a1"));         //--// need to put in new hash of genesis block merkle root - Byteswapped
        vFixedSeeds.clear();         vSeeds.clear();         fDefaultConsistencyChecks = true;        fRequireStandard = false;        fMineBlocksOnDemand = true;
        checkpointData = {{{0, uint256S("0x00000000c169e628ecaf7f1ae833aba5bdb634491d1e57f587aa9088ec2133b4")},}};                //--// need to put in new hash of genesis block            
        chainTxData = ChainTxData{
            1577032012,                                                                                                           //--// need to put in new Unix time
            0,
            0        };
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};                 base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};    	bech32_hrp = "ebrt"; 
    }};
static std::unique_ptr<CChainParams> globalChainParams;
const CChainParams &Params() {    assert(globalChainParams);    return *globalChainParams;}
std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain){
    if (chain == CBaseChainParams::MAIN)                                    return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)                            return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)                            return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));   }
void SelectParams(const std::string& network){    SelectBaseParams(network);                                              globalChainParams = CreateChainParams(network); }
void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout){    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout); }