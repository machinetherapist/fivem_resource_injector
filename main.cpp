
auto injector() -> void {

    LoadResource_Proto LoadResource = (LoadResource_Proto)(GetModuleHandleW(L"citizen-resources-client.dll") + 0x24540);

    while (true) {
        if (GetAsyncKeyState(VK_F3)) {

            LoadResource(0x0, "http://localhost:30120/test/resource.rpf");

        }
    }

}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)injector, 0, 0, 0);

    return TRUE;
}

