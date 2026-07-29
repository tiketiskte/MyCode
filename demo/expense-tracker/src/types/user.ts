export interface UserProfile {
  display_name: string;
  avatar: string | null;
}

export interface User {
  id: number;
  username: string;
  profile: UserProfile;
}
