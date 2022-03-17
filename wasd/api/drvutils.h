#pragma once

void startdriver()
{
	driver().handle_driver();

	if (!driver().is_loaded())
	{
		cout << xor_a("    driver initialize...") << endl;
		mmap_driver();
	}

	Sleep(3000);

	driver().handle_driver();
	driver().is_loaded() ? cout << xor_a("    driver initialized!") << endl : cout << xor_a("    driver initialize error :<") << endl;
}

